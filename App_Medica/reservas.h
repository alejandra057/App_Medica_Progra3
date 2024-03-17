#ifndef RESERVAS_H
#define RESERVAS_H

#include <QString>

class Reservas
{
public:
    struct STReservaciones
    {
        QString code="";
        QString nombre="";
        QString fecha="";
        QString horainicio="";
        QString horafinal="";
        QString namedoctor="";
        QString observacion="";

    };

    Reservas();

    bool Nuevareservacion(QString code,QString numsala,QString nombre,QString Fecha,QString horainicio,QString horafinal,QString namedoctor,QString observaciones);
    bool ModificarReservacion(QString code,QString nombre, QString fecha,QString horainicio,QString horafinal,QString namedoctor,QString observaciones);
    bool EliminarReservacion(QString code);
    STReservaciones Revisarcodigo(QString code);

    STReservaciones ObtenerReservacion() const {
        return reservacion;
    }

    void ModificarReservacion(const STReservaciones& nuevaReservacion) {
        reservacion = nuevaReservacion;
    }

private:
    STReservaciones reservacion;
};

#endif
