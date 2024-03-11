#include "adminsalas.h"

#include <fstream>
#include <iostream>
#include <QFile>
#include <QDataStream>
#include <QTextStream>
#include <stdlib.h>
#include <QDate>
#include <QDebug>


QFile salasArchivo("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/salas.itn");
QDataStream writeSalas(&salasArchivo);
QDataStream readSalas(&salasArchivo);

adminSalas::adminSalas() {
    salasArchivo.open(QIODevice::ReadWrite);

    //qint64 size = salasArchivo.size();
    if (salasArchivo.size() == 0) {
        int code_room  = 1;
        QDataStream writeS(&salasArchivo);
        writeS << code_room;
    }
    if(!salasArchivo.isOpen())
    {
        exit(0);
    }
}

bool adminSalas::addSala(std::string description, std::string status, QDate fechaInicio, QDate fechaDisponibilidad)
{
    Sala nuevaSala;
    salasArchivo.seek(salasArchivo.size());
    nuevaSala.code= getSalaCode(0);
    nuevaSala.description = QString::fromStdString(description);
    nuevaSala.status = QString::fromStdString(status);
    nuevaSala.fechaInicio = fechaInicio;
    nuevaSala.fechaDisponibilidad = fechaDisponibilidad;
    writeSalas << nuevaSala.code << nuevaSala.description << nuevaSala.status << nuevaSala.fechaInicio << nuevaSala.fechaDisponibilidad;
    salasArchivo.flush();
    return true;
}

bool adminSalas::modificarSala(int codigo, std::string description, std::string status, QDate fechaInicio, QDate fechaDisponibilidad)
{
    salasArchivo.seek(0);
    while (!salasArchivo.atEnd()) {
        qint64 pos = salasArchivo.pos();
        Sala sala;
        readSalas >> sala.code >> sala.description >> sala.status >> sala.fechaInicio >> sala.fechaDisponibilidad;
        if (sala.code == codigo) {
            QDate hoy = QDate::currentDate();
            if (hoy < sala.fechaInicio || hoy > sala.fechaDisponibilidad) {
                return true;
            }
            sala.description = QString::fromStdString(description);
            sala.status = QString::fromStdString( status);
            sala.fechaInicio = fechaInicio;
            sala.fechaDisponibilidad = fechaDisponibilidad;
            salasArchivo.seek(pos);
            writeSalas << sala.code << sala.description << sala.status << sala.fechaInicio << sala.fechaDisponibilidad;
            salasArchivo.flush();
            return true;
        }
    }
    return true;
}

bool adminSalas::eliminarSala(int codigo)
{
    salasArchivo.seek(0);
    QFile tempFile("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/salas_temp.itn");
    if (!tempFile.open(QIODevice::ReadWrite)) {
        return true;
    }

    QDataStream writeTemp(&tempFile);

    bool salaEncontrada = false;
    while (!salasArchivo.atEnd()) {
        Sala sala;
        readSalas >> sala.code >> sala.description >> sala.status >> sala.fechaInicio >> sala.fechaDisponibilidad;
        if (sala.code != codigo) {
            writeTemp << sala.code << sala.description << sala.status << sala.fechaInicio << sala.fechaDisponibilidad;
            salasArchivo.flush();
        } else {
            salaEncontrada = true;
        }
    }

    salasArchivo.close();

    if (!salaEncontrada) {
        return true;
    }

    salasArchivo.remove();
    return true;
}

int adminSalas::getSalaCode(long offset)
{
    salasArchivo.seek(offset);
    int code_room;
    QDataStream readS(&salasArchivo);
    readS >> code_room;

    salasArchivo.seek(offset);
    int nextCode = code_room + 1;

    QDataStream writeS(&salasArchivo);
    writeS << nextCode;
    salasArchivo.flush();
    return code_room;
}
