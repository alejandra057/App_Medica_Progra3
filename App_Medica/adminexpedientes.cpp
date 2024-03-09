#include "adminexpedientes.h"
//para los archivos
#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QTextStream>

QFile ExpedientesAdmin("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/Expedientes.itn");
QDataStream write (&ExpedientesAdmin);

AdminExpedientes::AdminExpedientes() {
    ExpedientesAdmin.open(QIODevice::ReadWrite);
    if(!ExpedientesAdmin.isOpen())
    {
        exit(0);
    }
}

bool AdminExpedientes::createNewExpediente(QString encabezado, QString nombrePaciente, QString Identidad, QString fechaNacimiento, QString Numero1, QString Mail1, QString adiconalContact, QString adiocionalPhone, QString adicionalmail, QString alegias, QString TipoSangre, QString EnfermedadesBase)
{
    NewExpediente Expedientes;
    Expedientes.Encabezado = encabezado;
    Expedientes.NombrePaciente = nombrePaciente;
    Expedientes.identidad = Identidad;
    Expedientes.FechaNacimiento = fechaNacimiento;
    Expedientes.numero1 = Numero1;
    Expedientes.mail1 = Mail1;
    Expedientes.AdiconalContact = adiconalContact;
    Expedientes.AdiocionalPhone = adiocionalPhone;
    Expedientes.Adicionalmail = adicionalmail;
    Expedientes.tipoSangre = TipoSangre;
    Expedientes.Alegias = alegias;
    Expedientes.enfermedadesBase = EnfermedadesBase;
    //No se cambiaran
    Expedientes.FechaCita="";
    Expedientes.Sintomas="";
    Expedientes.Observaciones="";
    Expedientes.diagnostico="";
    Expedientes.Recomendaciones="";
    Expedientes.newCita="";
    Expedientes.adicionalComents="";
    ExpedientesAdmin.seek(ExpedientesAdmin.size());
    write<<Expedientes.Encabezado<<Expedientes.NombrePaciente<<Expedientes.identidad<<Expedientes.FechaNacimiento<<Expedientes.numero1<<Expedientes.mail1<<Expedientes.AdiconalContact<<Expedientes.AdiocionalPhone<<Expedientes.Adicionalmail<<Expedientes.tipoSangre<<Expedientes.Alegias<<Expedientes.enfermedadesBase<<Expedientes.FechaCita<<Expedientes.Sintomas<<Expedientes.Observaciones<<Expedientes.diagnostico<<Expedientes.Recomendaciones<<Expedientes.newCita<<Expedientes.adicionalComents;
    //writeandwrite<<Expedientes.Encabezado<<Expedientes.NombrePaciente<<Expedientes.identidad;
    ExpedientesAdmin.flush();
    return true;
}

bool AdminExpedientes::addToExpediente(QString FechaCita, QString Sintomas, QString Observaciones, QString diagnostico, QString Recomendaciones, QString newCita, QString adicionalComents)
{
    return false;
}
