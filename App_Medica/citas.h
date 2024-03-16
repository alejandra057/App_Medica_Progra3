#ifndef CITAS_H
#define CITAS_H
#include <QString>
#include <QDate>
#include <QTime>
class Citas
{
    struct Datoscitas
    {
        QString nombre="";
        QString fecha="";
        QString hora="";
    };
public:
    Citas();

    bool CrearCitas(QString nombre, QString fecha, QString hora);
    bool ModificarCitas(QString cita);
    bool EliminarCitas(QString cita);
    QString ConsultarCitas(QString cita);
};

#endif // CITAS_H
