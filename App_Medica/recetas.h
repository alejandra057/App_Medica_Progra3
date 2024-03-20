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

    Recetas();

    bool crearNuevaReceta(long code, const QStringList& medicamento, const QString& dosis);
    bool searchRecetaFecha(QString fecha);
    bool searchRecetaPaciente(QString paciente);


private:
    newRecetas receta;
};

#endif
