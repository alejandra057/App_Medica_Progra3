#include "citas.h"

#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QTime>
#include <QTextStream>

QFile crearcitas("Citas.itn");
//QFile ExpedientesAdmin("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/Citas.itn");
QDataStream cin (&crearcitas);
Citas::Citas()
{
    crearcitas.open(QIODevice::ReadWrite);
    if(!crearcitas.isOpen())
    {
        exit(0);
    }
}
bool Citas::CrearCitas(QString nombre, QString fecha, QString hora)
{
    Datoscitas datos;
    crearcitas.seek(crearcitas.size());
    datos.nombre=nombre;
    datos.fecha=fecha;
    datos.hora=hora;
    crearcitas.seek(crearcitas.size());
    cin<<datos.nombre<<datos.fecha<<datos.hora;
    return true;
}
bool Citas::ModificarCitas(QString cita)
{

}

bool Citas::EliminarCitas(QString cita)
{

}

QString Citas::ConsultarCitas(QString cita)
{

}
