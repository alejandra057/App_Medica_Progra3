#ifndef RESERVAS_H
#define RESERVAS_H

#include <QString>

class Reservas
{
    struct Reservaciones
    {
        QString nombre="";
        QString fecha="";
        QString horainicio="";
        QString horafinal="";
        QString namedoctor="";
        QString observacion="";

    };
public:
    Reservas();

    bool Nuevareservacion(QString nombre,QString Fecha,QString horainicio,QString horafinal,QString namedoctor,QString observaciones);
    bool ModificarReservacion(QString nombre, QString fecha,QString horainicio,QString horafinal,QString namedoctor,QString observaciones);
    bool EliminarReservacion();
};

#endif // RESERVAS_H
