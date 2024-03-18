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
    QFile Room("Salas.arc");
    if (!Room.open(QIODevice::Append)){
        return false;
    }
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
    Room.close();
    return true;
}

long AdminSalas::getSala_Actal()
{
    QFile Room("Salas.arc");
    QDataStream leercode(&Room);
    if (!Room.open(QIODevice::ReadOnly)){
        return false;
    }
    Room.flush();
    Room.seek(bytes);
    QString Code, Descripcion, Status, Fechainicio, Fechafindisponibilidad,HoraInicio, HoraFinal;
    leercode >> Code >> Descripcion >> Status >> Fechainicio >> Fechafindisponibilidad >> HoraInicio >> HoraFinal;
    if (Status=="Disponible"){
        bytes=Room.pos();
        return Code.toLong();
    }
    bytes=Room.pos();
    Room.close();
    return -1;

}




bool AdminSalas::BuscarCodigo(QString code)
{
    QFile Room("Salas.arc");

    if (!Room.open(QIODevice::ReadOnly)) {
          exit(0);
    }

    QDataStream leer3(&Room);
    Room.seek(0);

    AdminSalas::newSala Sala;
    while (!leer3.atEnd())
    {
      leer3 >> Sala.Code >> Sala.Descripcion >> Sala.Status >> Sala.FechaInicio >> Sala.FechaFinDisponibilidad >> Sala.HoraInicio >> Sala.HoraFinal;
        if (Sala.Code == code)
        {
            return true;
        }
    }

    return false;
}

bool AdminSalas::modificateSala(QString code, QString descripcion, QString status, QString fechainicio, QString fechafindisponibilidad, QString horainicio, QString horafinal)
{
    /*
    Reservaciones reservas;
    QFile Reservaciones("Reservaciones.itn");
    if (!Reservaciones.open(QIODevice::ReadWrite)) {
        exit(0);
    }
    */

    QFile Room("Salas.arc");
    if (!Room.open(QIODevice::ReadWrite)) {
         exit(0);
    }

    QDataStream escribir(&Room);
    QDataStream leer(&Room);

    AdminSalas::newSala temp;
    Room.seek(0);
    while (!leer.atEnd())
    {
        long pos = Room.pos();
        leer >> temp.Code >> temp.Descripcion >> temp.Status >> temp.FechaInicio >> temp.FechaFinDisponibilidad >> temp.HoraInicio >> temp.HoraFinal;

        if (temp.Code == code)
        {

            /*
            if (Reservaciones.FechaInicio == fechainicio && Reservaciones.HoraInicio == horainicio) {

                Rervaciones.close();

                return false;
            }

            if (temp.FechaInicio < fechainicio || temp.FechaInicio > fechafindisponibilidad) {
                Room.close();

                return false;
            }
            if (temp.FechaFinDisponibilidad < fechainicio) {
                Room.close();

                return false;
            }

            if (temp.FechaInicio > fechafindisponibilidad) {
                Room.close();

                return false;
            }
            */
            temp.Descripcion = descripcion;
            temp.FechaInicio = fechainicio;
            temp.FechaFinDisponibilidad = fechafindisponibilidad;
            temp.HoraInicio = horainicio;
            temp.HoraFinal = horafinal;
            Room.seek(pos);
            escribir << temp.Code << temp.Descripcion << temp.Status << temp.FechaInicio << temp.FechaFinDisponibilidad << temp.HoraInicio << temp.HoraFinal;
            Room.flush();
        }


    }


    Room.close();
   // Rerservaciones.close();
    return true;
}





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
