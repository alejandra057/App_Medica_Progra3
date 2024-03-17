#include "reservas.h"
#include "adminsalas.h"
#include "admincodes.h"
#include <QString>
#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QTime>
#include <QMessageBox>

QFile Reservaciones("Reservas.itn");
//QFile ExpedientesAdmin("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/Reservas.itn");
QDataStream writee (&Reservaciones);
Reservas::Reservas()
{
    Reservaciones.open(QIODevice::ReadWrite);
    if(!Reservaciones.isOpen())
    {
        exit(0);
    }
}

bool Reservas::Nuevareservacion(QString code,QString numsala, QString nombre, QString Fecha, QString horainicio, QString horafinal, QString namedoctor, QString observaciones)
{
    AdminCodes codes;
    AdminSalas salas;
    QFile Room("Salas.arc");
    if (!Room.open(QIODevice::ReadOnly))
    {
     QMessageBox::information(nullptr, "Error", "No se pudo abrir el archivo de salas");
        return false;
    }
    QDataStream leer(&Room);
    while (!leer.atEnd())
    {
        AdminSalas::newSala Sala = salas.obtenerSalaActual();
        leer >> Sala.Code >> Sala.Descripcion >> Sala.Status >> Sala.FechaInicio >> Sala.FechaFinDisponibilidad;
         if (Sala.Code == numsala)
        {
            QDate fecha = QDate::fromString(Fecha, "dd/MM/yyyy");
            QDate fechaInicio = QDate::fromString(Sala.FechaInicio, "dd/MM/yyyy");
            QDate fechaFin = QDate::fromString(Sala.FechaFinDisponibilidad, "dd/MM/yyyy");

            if (fecha >= fechaInicio && fecha <= fechaFin)
            {
                STReservaciones reservar;
                reservar.code = code;
                reservar.nombre = nombre;
                reservar.fecha = Fecha;
                reservar.horainicio = horainicio;
                reservar.horafinal = horafinal;
                reservar.namedoctor = namedoctor;
                reservar.observacion = observaciones;

                Reservaciones.seek(Reservaciones.size());
                writee << reservar.code << reservar.nombre << reservar.fecha << reservar.horainicio << reservar.horafinal << reservar.namedoctor << reservar.observacion;
                Reservaciones.flush();
                Room.close();
                return true;
            } else {
                Room.close();
                  QMessageBox::information(nullptr, "Error", "Fecha no disponible");
                return false;
            }
        }
    }
      QMessageBox::information(nullptr, "Error", "No se ");

    Room.close();
    return false;
}

Reservas::STReservaciones Reservas::Revisarcodigo(QString code)
{
    STReservaciones reservar;
    QDataStream leerr(&Reservaciones);
    Reservaciones.seek(0);
    while(!leerr.atEnd())
    {
        leerr >> reservar.code >> reservar.nombre >> reservar.fecha >> reservar.horainicio >> reservar.horafinal >> reservar.namedoctor >> reservar.observacion;
        if (reservar.code == code)
        {
            return reservar;
        }
    }
    qDebug() << "reservar code." << reservar.code << " code: " << code;
    return STReservaciones();
}

bool Reservas::ModificarReservacion(QString code, QString nombre, QString fecha, QString horainicio, QString horafinal, QString namedoctor, QString observaciones)
{
    QFile tempFile("temp.itn");
    if (!tempFile.open(QIODevice::ReadWrite))
    {
        qDebug() << "No se pudo abrir el archivo temporal.";
        return false;
    }

    QDataStream escribir(&tempFile);
    Reservaciones.seek(0);
    QDataStream leer(&Reservaciones);

    while (!leer.atEnd())
    {
        STReservaciones temp;
        leer >> temp.code >> temp.nombre >> temp.fecha >> temp.horainicio >> temp.horafinal >> temp.namedoctor >> temp.observacion;
        if (temp.code == code)
        {
            temp.nombre = nombre;
            temp.fecha = fecha;
            temp.horainicio = horainicio;
            temp.horafinal = horafinal;
            temp.namedoctor = namedoctor;
            temp.observacion = observaciones;
        }
        escribir << temp.code << temp.nombre << temp.fecha << temp.horainicio << temp.horafinal << temp.namedoctor << temp.observacion;
    }

    tempFile.close();
    Reservaciones.remove();
    tempFile.rename("Reservas.itn");

    return true;
}


bool Reservas::EliminarReservacion(QString code)
{
    QFile tempFile("temp.itn");
    if (!tempFile.open(QIODevice::ReadWrite))
    {
        qDebug() << "No se pudo abrir el archivo temporal.";
        return false;
    }

    QDataStream escribir(&tempFile);
    Reservaciones.seek(0);
    QDataStream leer(&Reservaciones);

    bool encontrado = false;
    while (!leer.atEnd())
    {
        STReservaciones temp;
        leer >> temp.code >> temp.nombre >> temp.fecha >> temp.horainicio >> temp.horafinal >> temp.namedoctor >> temp.observacion;
        if (temp.code == code)
        {
            encontrado = true;
            continue;
        }
        escribir << temp.code << temp.nombre << temp.fecha << temp.horainicio << temp.horafinal << temp.namedoctor << temp.observacion;
    }

    tempFile.close();
    Reservaciones.remove();
    tempFile.rename("Reservas.itn");

    if (!encontrado)
    {
        return false;
    }

    return true;
}
