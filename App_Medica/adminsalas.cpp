#include "adminsalas.h"
#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QTextStream>
#include "admincodes.h"
#include "reservas.h"
#include <QMessageBox>
//pa windows
//QFile Room("Salas.arc");
//pa kenny
QFile Room("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/Salas.itn");


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

bool AdminSalas::createNewSala(QString code, QString descripcion, QString status, QString fechainicio, QString fechafindisponibilidad,QString horainicio, QString horafinal)
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

bool AdminSalas::modificateSala(QString code, QString descripcion, QString status, QString fechainicio, QString fechafindisponibilidad, QString horainicio, QString horafinal) {
    Room.seek(0);
    QDataStream leer2(&Room);
    AdminSalas::newSala sala;

    while (!leer2.atEnd()) {
        long pos = Room.pos();
        leer2 >> sala.Code >> sala.Descripcion >> sala.Status >> sala.FechaInicio >> sala.FechaFinDisponibilidad >> sala.HoraInicio >> sala.HoraFinal;

        if (sala.Code == code) {

            //QFile Reservaciones("Reservaciones.itn");
            QFile Reservaciones("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/Reservaciones.itn");
            QDataStream leer_r(&Reservaciones);
            if (Reservaciones.open(QIODevice::ReadOnly)) {
                Reservas::STReservaciones reservass;
                while (!leer_r.atEnd()) {
                    leer_r >> reservass.code >> reservass.fecha >> reservass.horafinal >> reservass.horainicio >> reservass.namedoctor >> reservass.nombre >> reservass.observacion;
                    if (reservass.code == code && reservass.fecha > fechafindisponibilidad) {
                        QMessageBox::information(nullptr, "Error", "Existen reservaciones fuera de la fecha de disponibilidad.");
                        return false;
                    }
                }

            }
            sala.Descripcion = descripcion;
            sala.Status = status;
            sala.FechaInicio = fechainicio;
            sala.FechaFinDisponibilidad = fechafindisponibilidad;
            sala.HoraInicio = horainicio;
            sala.HoraFinal = horafinal;
            Room.seek(pos);
            QDataStream escribir2(&Room);
            escribir2 << sala.Code << sala.Descripcion << sala.Status << sala.FechaInicio << sala.FechaFinDisponibilidad << sala.HoraInicio << sala.HoraFinal;
            Room.flush();
            return true;
        }
    }


    QMessageBox::information(nullptr, "Error", "La sala no existe.");
    return false;
}


bool AdminSalas::eliminarSala(QString code, QString usuarioActual) {
    //QFile Reservaciones("Reservaciones.itn");
    QFile Reservaciones("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/Reservaciones.itn");
    QDataStream leer_r(&Reservaciones);
    if (Reservaciones.open(QIODevice::ReadOnly)) {
        while (!leer_r.atEnd()) {
            Reservas::STReservaciones reservass;
            leer_r >> reservass.code >> reservass.fecha >> reservass.horafinal >> reservass.horainicio >> reservass.namedoctor >> reservass.nombre >> reservass.observacion;
            if (reservass.code == code) {
                QMessageBox::information(nullptr, "Error", "No se puede eliminar la sala porque tiene reservaciones asociadas.");
                return false;
            }
        }
    }

    QMessageBox::StandardButton confirmacion;
    confirmacion = QMessageBox::question(nullptr, "Confirmar eliminación", "¿Estás seguro de que deseas eliminar esta sala?",
                                         QMessageBox::Yes | QMessageBox::No);
    if (confirmacion == QMessageBox::No) {
        return false;
    }


    if (usuarioActual != "admin") {
        QMessageBox::critical(nullptr, "Error", "No tienes permisos para realizar esta acción.");
        return false;
    }

    Room.seek(0);
    AdminSalas::newSala sala;
    while (!leer.atEnd()) {
        long pos = Room.pos();
        leer >> sala.Code >> sala.Descripcion >> sala.Status >> sala.FechaInicio >> sala.FechaFinDisponibilidad >> sala.HoraInicio >> sala.HoraFinal;
        if (sala.Code == code) {

            Room.seek(pos);
            Room.write("0", 1); // Sobrescribir el código de la sala con "0" para indicar que está eliminada
            QMessageBox::information(nullptr, "Éxito", "La sala ha sido eliminada correctamente.");
            return true; // La sala fue eliminada
        }
    }

    // Si llegamos aquí, la sala no fue encontrada
    QMessageBox::information(nullptr, "Error", "No se encontró la sala para eliminar.");
    return false;
}
