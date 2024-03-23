#ifndef RECETAS_H
#define RECETAS_H

#include <QString>
class Recetas
{
public:
    struct newRecetas
    {
        QString fecha="";
        QString paciente="";
        QString medicamento="";
        QString dosis="";

    };


public:
    Recetas();
    bool crearNuevaReceta(long code, QString medicamento, QString dosis);
    QString searchRecetaFecha(QString fecha);
    QString searchRecetaPaciente(QString paciente);


private:
    newRecetas receta;
};

#endif
