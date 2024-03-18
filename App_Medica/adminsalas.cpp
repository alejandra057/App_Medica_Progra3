#include "adminsalas.h"
#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QTextStream>
#include "admincodes.h"
#include "reservas.h"
#include <QMessageBox>
//pa windows
QFile Room("Salas.arc");
//pa kenny
//QFile Room("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/Salas.itn");


QDataStream escribir(&Room);
QDataStream leer(&Room);
long bytes;
AdminSalas::AdminSalas() {
     bytes=0;
    Room.open(QIODevice::ReadWrite);
    if(!Room.isOpen())
    {
        exit(0);
    }
}

bool AdminSalas::createNewSala(QString code,QString descripcion, QString status, QString fechainicio, QString fechafindisponibilidad,QString horainicio, QString horafinal)
{
    newSala Sala;
    Room.seek(Room.size());
    Sala.Code=code;
    Sala.Descripcion = descripcion;
    Sala.Status = status;
    Sala.FechaInicio = fechainicio;
    Sala.FechaFinDisponibilidad = fechafindisponibilidad;
    Sala.HoraInicio= horainicio;
    Sala.HoraFinal= horafinal;
    Room.seek(Room.size());
    escribir<<Sala.Code<<Sala.Descripcion<<Sala.Status<<Sala.FechaInicio<<Sala.FechaFinDisponibilidad<<Sala.HoraInicio<<Sala.HoraFinal;
    Room.flush();
    return true;
}

long AdminSalas::getSala_Actal()
{

    Room.seek(bytes);
    QString Code, Descripcion, Status, Fechainicio, Fechafindisponibilidad,HoraInicio, HoraFinal;
    leer >> Code >> Descripcion >> Status >> Fechainicio >> Fechafindisponibilidad >> HoraInicio >> HoraFinal;
    if (Status=="Disponible"){
        bytes=Room.pos();
        return Code.toLong();
    }
    bytes=Room.pos();
    return -1;

}




bool AdminSalas::BuscarCodigo(QString code)
{

    QDataStream leer1(&Room);
    Room.seek(0);

    AdminSalas::newSala Sala;
    while (!leer1.atEnd())
    {
      leer >> Sala.Code >> Sala.Descripcion >> Sala.Status >> Sala.FechaInicio >> Sala.FechaFinDisponibilidad >> Sala.HoraInicio >> Sala.HoraFinal;
        if (Sala.Code == code)
        {
            return true;
        }
    }

    return false;
}


bool AdminSalas::modificateSala(QString code, QString descripcion, QString status, QString fechainicio, QString fechafindisponibilidad, QString horainicio, QString horafinal)
{

    QDataStream escribir2(&Room);
    QDataStream leer2(&Room);
    //abrir archivo reservaciones
    Reservas reservaciones;
    QFile Reservaciones("Reservaciones.itn");
    QDataStream leer_r(&Reservaciones);
    if (!Reservaciones.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(nullptr, "Error", "No se pudo abrir el archivo de salas");
        return false;
    }
    AdminSalas::newSala sala;
    Reservas:: STReservaciones reservass;


    bool reservas_fuera = false;
    while (!leer_r.atEnd()) {
        leer_r >> reservass.code >> reservass.fecha >> reservass.horafinal >> reservass.horainicio >> reservass.namedoctor >> reservass.nombre >> reservass.observacion;
        if (reservass.code == code && reservass.fecha > fechafindisponibilidad) {
            reservas_fuera = true;
            break;
        }
    }
    Reservaciones.seek(0);

    if (!reservas_fuera) {
        while (!leer2.atEnd()) {
            long pos = Room.pos();
            leer2 >> sala.Code >> sala.Descripcion >> sala.Status >> sala.FechaInicio >> sala.FechaFinDisponibilidad >> sala.HoraInicio >> sala.HoraFinal;

            if (sala.Code == code) {
                sala.Descripcion = descripcion;
                sala.Status = status;
                sala.FechaInicio = fechainicio;
                sala.FechaFinDisponibilidad = fechafindisponibilidad;
                sala.HoraInicio = horainicio;
                sala.HoraFinal = horafinal;
                Room.seek(pos);
                escribir2 << sala.Code << sala.Descripcion << sala.Status << sala.FechaInicio << sala.FechaFinDisponibilidad << sala.HoraInicio << sala.HoraFinal;
                Room.flush();
                break;
            }
        }
    } else {
        QMessageBox::information(nullptr, "Error", "Existen reservaciones fuera de la fecha de disponibilidad.");
    }

    return true;


}

/*bool Reservas::EliminarReservacion(QString code)
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
*/

//faltan reservaciones
/*bool AdminSalas::eliminarSala(QString descripcion)
{
    Salas.open(QIODevice::ReadWrite);
    if(!Salas.isOpen())
    {
        exit(0);// No se pudo abrir el archivo
    }
    while (!read.atEnd()) {
        newSala sala;
        read >> Sala.Descripcion >> Sala.Status >> Sala.FechaInicio >> Sala.FechaFinDisponibilidad;
        Sala.append(sala);
    }

    bool reservaciones_previas = false;
    for (const auto& Sala : salas) {
        if (sala.Descripcion == descripcion && sala.Status != "Disponible") {
            reservaciones_previas = true;
            break;
        }
    }

    if (reservaciones_previas) {
        return false;
    }

    salas.erase(std::remove_if(salas.begin(), salas.end(), [descripcion](const newSala& sala) {
                    return Sala.Descripcion == descripcion;
                }), salas.end());

    Salas.seek(0);
    for (const auto& Sala : salas) {
        write << Sala.Descripcion << Sala.Status << Sala.FechaInicio << Sala.FechaFinDisponibilidad;
    }

    Salas.resize(Salas.pos());

    return true;
}
*/
