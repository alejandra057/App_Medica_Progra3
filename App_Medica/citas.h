#ifndef CITAS_H
#define CITAS_H
#include <QString>
#include <QDate>
#include <QTime>
class Citas
{
    struct Datoscitas
    {
        QString code="";
        QString nombre="";
        QString fecha="";
        QString hora="";
    };
public:
    Citas();

    bool CrearCitas(QString code,QString nombre, QString fecha, QString hora);
    bool ModificarCitas(QString code,QString nombre, QString fecha, QString hora);
    bool EliminarCitas(QString cita);
    QString ConsultarCitas(QString cita);
    Datoscitas buscarcita(QString code);
    long getCita_Actal();
};

#endif // CITAS_H
