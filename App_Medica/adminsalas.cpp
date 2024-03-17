#include "adminsalas.h"
#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QTextStream>
#include "admincodes.h"
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

bool AdminSalas::createNewSala(QString code,QString descripcion, QString status, QString fechainicio, QString fechafindisponibilidad)
{
    QFile Room("Salas.arc");
    if (!Room.open(QIODevice::Append)){
        return false;
    }
    newSala Sala;
    Room.seek(Room.size());
    /*AdminCodes codes;
    long codigo=codes.NextcodigoSala();
    code=QString::number(codigo);*/
    Sala.Code=code;
    Sala.Descripcion = descripcion;
    Sala.Status = status;
    Sala.FechaInicio = fechainicio;
    Sala.FechaFinDisponibilidad = fechafindisponibilidad;
    Room.seek(Room.size());
    escribir<<Sala.Code<<Sala.Descripcion<<Sala.Status<<Sala.FechaInicio<<Sala.FechaFinDisponibilidad;
    Room.flush();
    Room.close();
    return true;
}

long AdminSalas::getSala_Actal()
{
    QFile Room("Salas.arc");
    if (!Room.open(QIODevice::ReadOnly)){
        return false;
    }
    Room.seek(bytes);
    QString Code, Descripcion, Status, Fechainicio, Fechafindisponibilidad;
    leer >> Code >> Descripcion >> Status >> Fechainicio >> Fechafindisponibilidad;
    Room.close();
    if (Status=="Disponible"){
        bytes=Room.pos();
        return Code.toLong();
    }
    bytes=Room.pos();

    return -1;

}



//faltan reservaciones
/*bool AdminSalas::modificateSala(QString descripcion, QString status, QString fechainicio, QString fechafindisponibilidad)
{
    Salas.open(QIODevice::ReadWrite);
    if(!Salas.isOpen())
    {
        exit(0);
    }

    while (!read.atEnd()) {
        newSala Sala;
        read >> Sala.Descripcion >> Sala.Status >> Sala.FechaInicio >> Sala.FechaFinDisponibilidad;
        Sala.append(Sala);
    }

    bool reservaciones = false;
    for (const auto& Sala : salas) {
        if (Sala.Descripcion == descripcion && Sala.Status != "Disponible" && Sala.FechaInicio < fechafindisponibilidad) {
            reservaciones = true;
            break;
        }
    }

    if (reservaciones) {
        return false;
    }

    for (auto& Sala : salas) {
        if (Sala.Descripcion == descripcion) {
            Sala.Status = status;
            Sala.FechaInicio = fechainicio;
            Sala.FechaFinDisponibilidad = fechafindisponibilidad;
            break;
        }
    }

    Salas.seek(0);
    for (const auto& Sala : salas) {
        write << Sala.Descripcion << Sala.Status << Sala.FechaInicio << Sala.FechaFinDisponibilidad;
    }
    Salas.resize(Salas.pos());
    return true;
}


//faltan reservaciones
bool AdminSalas::eliminarSala(QString descripcion)
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
