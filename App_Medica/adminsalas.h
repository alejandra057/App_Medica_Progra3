#ifndef ADMINSALAS_H
#define ADMINSALAS_H
#include <QString>
#include <QFile>
#include <QDataStream>
class AdminSalas
{
public:
    struct newSala
    {
        QString Code="";
        QString Descripcion ="";
        QString Status="";
        QString FechaInicio="";
        QString FechaFinDisponibilidad="";
        QString HoraInicio="";
        QString HoraFinal="";
    };

    AdminSalas();
    bool createNewSala(QString code, QString descripcion, QString status, QString fechainicio, QString fechafindisponibilidad, QString horainicio, QString horafinal);
    bool modificateSala(QString code,QString descripcion, QString status, QString fechainicio, QString fechafindisponibilidad,QString horainicio, QString horafinal);
    bool eliminarSala(QString code);
    long getSala_Actal();
    bool BuscarCodigo(QString code);
    newSala obtenerSalaActual() const {
        return sala;
    }

private:
    newSala sala;
};

#endif
