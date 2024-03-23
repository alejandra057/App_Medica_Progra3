#include "citas.h"

#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QTime>
#include <QTextStream>

//QFile crearcitas("Citas.itn");
QFile crearcitas("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/Citas.itn");
//QFile ExpedientesAdmin("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/Citas.itn");
QDataStream cin (&crearcitas);
long bytess;
Citas::Citas()
{
    bytess=0;
    crearcitas.open(QIODevice::ReadWrite);
    if(!crearcitas.isOpen())
    {
        exit(0);
    }
}
bool Citas::CrearCitas(QString code,QString nombre, QString fecha, QString hora)
{
    crearcitas.seek(0);

    while (!cin.atEnd())
    {
        Datoscitas datos;
        cin >>datos.code>> datos.nombre >> datos.fecha >> datos.hora;
        if (datos.fecha == fecha && datos.hora == hora)
        {
            qDebug() << "ya esta reservada.";
            return false;
        }
    }
    Datoscitas datos;
    crearcitas.seek(crearcitas.size());
    datos.code=code;
    datos.nombre=nombre;
    datos.fecha=fecha;
    datos.hora=hora;
    crearcitas.seek(crearcitas.size());
    cin<< datos.code <<datos.nombre<<datos.fecha<<datos.hora;
    crearcitas.flush();
    return true;
}
bool Citas::ModificarCitas(QString code,QString nombre, QString fecha, QString hora)
{
    Datoscitas datos;
    QFile tempFile("temp.itn");
    if (!tempFile.open(QIODevice::ReadWrite))
    {
        qDebug() << "No se pudo abrir el archivo en temp.";
        return false;
    }

    QDataStream escribir(&tempFile);
    crearcitas.seek(0);
    QDataStream leer(&crearcitas);

    bool encontrado = false;
    while (!leer.atEnd())
    {
        leer >>datos.code>> datos.nombre >> datos.fecha >> datos.hora;
        qDebug() << "Datos.code "<< datos.code<< " code: "<<code <<" Datos.nombre: "<<datos.nombre;
        if (datos.code == code)
        {
            datos.nombre=nombre;
            datos.fecha = fecha;
            datos.hora = hora;
            encontrado = true;
        }
        escribir <<datos.code<< datos.nombre << datos.fecha << datos.hora;
    }

    tempFile.close();
    crearcitas.remove();
    tempFile.rename("Citas.itn");

    if (!encontrado)
    {
        qDebug() << "No se encontró la cita con el nombre especificado.";
        return false;
    }

    return true;
}

bool Citas::EliminarCitas(QString cita)
{
    QFile tempFile("temp.itn");
    if (!tempFile.open(QIODevice::ReadWrite))
    {
        qDebug() << "No se pudo abrir el archivo temporal.";
        return false;
    }

    QDataStream escribir(&tempFile);
    crearcitas.seek(0);
    QDataStream leer(&crearcitas);

    bool encontrado = false;
    while (!leer.atEnd())
    {
        Datoscitas datos;
        leer >>datos.code >> datos.nombre >> datos.fecha >> datos.hora;
        if (datos.code == cita)
        {
            encontrado = true;
            continue;
        }
        escribir <<datos.code<< datos.nombre << datos.fecha << datos.hora;
    }

    tempFile.close();
    crearcitas.remove();
    //tempFile.rename("Citas.itn");
    tempFile.rename("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/Citas.itn");

    if (!encontrado)
    {
        qDebug() << "No se encontró la cita con el nombre especificado.";
        return false;
    }

    return true;
}

QString Citas::ConsultarCitas(QString cita)
{
    crearcitas.seek(0);
    QDataStream leer(&crearcitas);

    while (!leer.atEnd())
    {
        Datoscitas datos;
        leer >>datos.code>> datos.nombre >> datos.fecha >> datos.hora;
        qDebug()<<"datos.code "<< datos.code <<" fecha desde consulta: "<<cita<<" datos.fecha: "<<datos.fecha;
        if (datos.fecha == cita)
        {
            qDebug()<<"Entra al if";
            //return Consultaporfecha(cita);
            return ConvertirDatosCitaAString(datos);

        }
    }

    return "Cita no encontrada";
}
Citas::Datoscitas Citas::Consultaporfecha(QString fecha){\

    Datoscitas datos;
    QDataStream leerr(&crearcitas);
    crearcitas.seek(0);
    while(!leerr.atEnd())
    {
        leerr >> datos.code >> datos.nombre >> datos.fecha >> datos.hora;
        if (datos.fecha == fecha)
        {
            return datos;
        }
    }
    qDebug() << "En consultaxfecha fecha datos." << datos.fecha << " fehca: " << fecha;
    return Datoscitas();
}
QString Citas::ConvertirDatosCitaAString(const Datoscitas& datos)
{
    return QString("Código: %1\nNombre: %2\nFecha: %3\nHora: %4")
        .arg(datos.code).arg(datos.nombre).arg(datos.fecha).arg(datos.hora);
}

Citas::Datoscitas Citas::buscarcita(QString code)
{

    Datoscitas datos;
    QDataStream leerr(&crearcitas);
     crearcitas.seek(0);
    while(!leerr.atEnd())
    {
        leerr >> datos.code >> datos.nombre >> datos.fecha >> datos.hora;
        if (datos.code == code)
        {
            return datos;
        }
    }
    qDebug() << "reservar code." << datos.code << " code: " << code;
    return Datoscitas();
}

long Citas::getCita_Actal()
{
    QDataStream leerr(&crearcitas);
    crearcitas.seek(bytess);
    QString Code, nombre, Fecha,Hora;
    leerr >> Code >> nombre >>  Fecha >> Hora;

        bytess=crearcitas.pos();
        return Code.toLong();

    //bytes=crearcitas.pos();
    //return -1;

}

QString Citas::getCitasEnRango(QString fechaInicio, QString fechaFin)
{
    Datoscitas cita;
    QDataStream leerr(&crearcitas);
    QString citasEnRango = " ";
    crearcitas.seek(0);
    QDate inicio = QDate::fromString(fechaInicio, "dd/MM/yyyy");
    QDate fin = QDate::fromString(fechaFin, "dd/MM/yyyy");
    while (!crearcitas.atEnd()) {
        leerr >> cita.code >> cita.nombre >> cita.fecha >> cita.hora;
        QDate fechaCita = QDate::fromString(cita.fecha, "dd/MM/yyyy");
        if (fechaCita >= inicio && fechaCita <= fin) {

            citasEnRango += "Código: " + cita.code + "\n";
            citasEnRango += "Nombre del Paciente: " + cita.nombre + "\n";
            citasEnRango += "Fecha de la cita: " + cita.fecha + "\n";
            citasEnRango += "Hora de la cita: " + cita.hora + "\n\n";
        }
    }
    if (citasEnRango == " ") {
        citasEnRango = "No se han encontrado citas en las fechas seleccionadas.";
    }
    return citasEnRango;
}
