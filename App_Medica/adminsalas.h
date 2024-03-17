#ifndef ADMINSALAS_H
#define ADMINSALAS_H
#include <QString>
#include <QFile>
#include <QDataStream>
class  AdminSalas
{
    struct newSala
    {
        QString Code="";
        QString Descripcion ="";
        QString Status="";
        QString FechaInicio="";
        QString FechaFinDisponibilidad="";

    };
public:
    AdminSalas();
    bool createNewSala(QString code,QString descripcion, QString status, QString fechainicio, QString fechafindisponibilidad);
    bool modificateSala(QString descripcion, QString status, QString fechainicio, QString fechafindisponibilidad);
    bool eliminarSala(QString descripcion);
    long getSala_Actal();
};
#endif
