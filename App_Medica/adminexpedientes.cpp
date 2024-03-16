#include "adminexpedientes.h"
//para los archivos
#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QTextStream>

QFile ExpedientesAdmin("Expedientes.itn");
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
    ExpedientesAdmin.seek(ExpedientesAdmin.size());
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

bool AdminExpedientes::addToExpediente(QString Nombrepaciente , QString identidad,QString FechaCita, QString Sintomas, QString Observaciones, QString diagnostico, QString Recomendaciones, QString newCita, QString adicionalComents)
{
    ExpedientesAdmin.seek(0);
    while (!ExpedientesAdmin.atEnd()) {
        NewExpediente expe;
        expe.FechaCita=FechaCita;
        expe.Sintomas=Sintomas;
        expe.Observaciones=Observaciones;
        expe.diagnostico=diagnostico;
        expe.Recomendaciones=Recomendaciones;
        expe.newCita=newCita;
        expe.adicionalComents=adicionalComents;
        write>>expe.Encabezado>>expe.NombrePaciente>>expe.identidad>>expe.FechaNacimiento>>expe.numero1>>expe.mail1>>expe.AdiconalContact>>expe.AdiocionalPhone>>expe.Adicionalmail>>expe.tipoSangre>>expe.Alegias>>expe.enfermedadesBase>>expe.FechaCita>>expe.Sintomas>>expe.Observaciones>>expe.diagnostico>>expe.Recomendaciones>>expe.newCita>>expe.adicionalComents;
        if (expe.NombrePaciente == Nombrepaciente && expe.identidad == identidad) {
            write<<expe.Encabezado<<expe.NombrePaciente<<expe.identidad<<expe.FechaNacimiento<<expe.numero1<<expe.mail1<<expe.AdiconalContact<<expe.AdiocionalPhone<<expe.Adicionalmail<<expe.tipoSangre<<expe.Alegias<<expe.enfermedadesBase<<expe.FechaCita<<expe.Sintomas<<expe.Observaciones<<expe.diagnostico<<expe.Recomendaciones<<expe.newCita<<expe.adicionalComents;
            return true;
        }
    }
    return false;
}

