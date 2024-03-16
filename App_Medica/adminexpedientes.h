#ifndef ADMINEXPEDIENTES_H
#define ADMINEXPEDIENTES_H
//para los archivos
#include <QString>
#include <QFile>
#include <QDataStream>
class AdminExpedientes
{
    struct NewExpediente
    {
        //datos creados por asistente
        QString Encabezado ="";
        QString NombrePaciente="";
        QString identidad=0;
        QString FechaNacimiento="";
        QString numero1=0;
        QString mail1="";
        QString AdiconalContact="";
        QString AdiocionalPhone=0;
        QString Adicionalmail="";
        QString tipoSangre="";
        QString Alegias="";
        QString enfermedadesBase="";
        //Datos creados por doctor
        QString FechaCita="";
        QString Sintomas="";
        QString Observaciones="";
        QString diagnostico="";
        QString Recomendaciones="";
        QString newCita="";
        QString adicionalComents="";
    };
public:
    AdminExpedientes();
    bool createNewExpediente(QString encabezado,QString nombrePaciente,QString Identidad,QString fechaNacimiento,QString Numero1,QString Mail1,QString adiconalContact,QString adiocionalPhone,QString adicionalmail,QString alegias,QString TipoSangre,QString EnfermedadesBase);
    bool addToExpediente(QString Nombrepaciente , QString identidad,QString FechaCita,QString Sintomas,QString Observaciones,QString diagnostico,QString Recomendaciones,QString newCita,QString adicionalComents);
};

#endif // ADMINEXPEDIENTES_H
