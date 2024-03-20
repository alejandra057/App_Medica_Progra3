#include "adminexpedientes.h"
//para los archivos
#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QTextStream>

QFile ExpedientesAdmin("Expedientes.itn");
//QFile ExpedientesAdmin("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/Expedientes.itn");
QDataStream write (&ExpedientesAdmin);


QFile ExpedientesEncabezado("ExpedientesEncabezado.itn");
//QFile ExpedientesEncabezado("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/ExpedientesEncabezado.itn");
QDataStream encabezadoWrite(&ExpedientesEncabezado);
AdminExpedientes::AdminExpedientes() {
    ExpedientesAdmin.open(QIODevice::ReadWrite);
    ExpedientesEncabezado.open(QIODevice::ReadWrite);
    if(!ExpedientesAdmin.isOpen())
    {
        exit(0);
    }
    if(!ExpedientesEncabezado.isOpen())
    {
        exit(0);
    }
}

bool AdminExpedientes::createNewExpediente(QString Codigo, QString nombrePaciente, QString Identidad, QString fechaNacimiento, QString Numero1, QString Mail1, QString adiconalContact, QString adiocionalPhone, QString adicionalmail, QString alegias, QString TipoSangre, QString EnfermedadesBase)
{
    NewExpediente Expedientes;
    ExpedientesAdmin.seek(ExpedientesAdmin.size());
    Expedientes.Codigo = Codigo;
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

    ExpedientesEncabezado.seek(ExpedientesEncabezado.size());
    encabezadoWrite<<Expedientes.Codigo<<Expedientes.identidad;
    ExpedientesEncabezado.flush();
    write<<Expedientes.Codigo<<Expedientes.NombrePaciente<<Expedientes.identidad<<Expedientes.FechaNacimiento<<Expedientes.numero1<<Expedientes.mail1<<Expedientes.AdiconalContact<<Expedientes.AdiocionalPhone<<Expedientes.Adicionalmail<<Expedientes.tipoSangre<<Expedientes.Alegias<<Expedientes.enfermedadesBase<<Expedientes.FechaCita<<Expedientes.Sintomas<<Expedientes.Observaciones<<Expedientes.diagnostico<<Expedientes.Recomendaciones<<Expedientes.newCita<<Expedientes.adicionalComents;
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
        write>>expe.Codigo>>expe.NombrePaciente>>expe.identidad>>expe.FechaNacimiento>>expe.numero1>>expe.mail1>>expe.AdiconalContact>>expe.AdiocionalPhone>>expe.Adicionalmail>>expe.tipoSangre>>expe.Alegias>>expe.enfermedadesBase>>expe.FechaCita>>expe.Sintomas>>expe.Observaciones>>expe.diagnostico>>expe.Recomendaciones>>expe.newCita>>expe.adicionalComents;
        if (expe.NombrePaciente == Nombrepaciente && expe.identidad == identidad) {
            write<<expe.Codigo<<expe.NombrePaciente<<expe.identidad<<expe.FechaNacimiento<<expe.numero1<<expe.mail1<<expe.AdiconalContact<<expe.AdiocionalPhone<<expe.Adicionalmail<<expe.tipoSangre<<expe.Alegias<<expe.enfermedadesBase<<expe.FechaCita<<expe.Sintomas<<expe.Observaciones<<expe.diagnostico<<expe.Recomendaciones<<expe.newCita<<expe.adicionalComents;
            ExpedientesAdmin.flush();
            return true;
        }
    }
    return false;
}

QString AdminExpedientes::getExpedientesInRange(QString fechaInicio, QString fechaFin)
{
    QString expedientesEnRango=" ";
    ExpedientesAdmin.seek(0);
    QDate inicio = QDate::fromString(fechaInicio, "dd/MM/yyyy");
    QDate fin = QDate::fromString(fechaFin, "dd/MM/yyyy");
    while (!ExpedientesAdmin.atEnd()) {
        NewExpediente expe;
        write>>expe.Codigo>>expe.NombrePaciente>>expe.identidad>>expe.FechaNacimiento>>expe.numero1>>expe.mail1>>expe.AdiconalContact>>expe.AdiocionalPhone>>expe.Adicionalmail>>expe.tipoSangre>>expe.Alegias>>expe.enfermedadesBase>>expe.FechaCita>>expe.Sintomas>>expe.Observaciones>>expe.diagnostico>>expe.Recomendaciones>>expe.newCita>>expe.adicionalComents;
        QString fechaExpediente = expe.FechaNacimiento;
        QDate fechaExpedienteDate = QDate::fromString(fechaExpediente, "dd/MM/yyyy");
        if (fechaExpedienteDate >= inicio && fechaExpedienteDate <= fin) {
            expedientesEnRango += "Codigo: " + expe.Codigo + "\n";
            expedientesEnRango += "Nombre del Paciente: " + expe.NombrePaciente + "\n";
            expedientesEnRango += "Identidad: " + expe.identidad + "\n";
            expedientesEnRango += "Fecha de Nacimiento: " + expe.FechaNacimiento + "\n";
            expedientesEnRango += "Número de Teléfono: " + expe.numero1 + "\n";
            expedientesEnRango += "Correo Electrónico: " + expe.mail1 + "\n";
            expedientesEnRango += "Contacto Adicional: " + expe.AdiconalContact + "\n";
            expedientesEnRango += "Teléfono Adicional: " + expe.AdiocionalPhone + "\n";
            expedientesEnRango += "Correo Electrónico Adicional: " + expe.Adicionalmail + "\n";
            expedientesEnRango += "Tipo de Sangre: " + expe.tipoSangre + "\n";
            expedientesEnRango += "Alergias: " + expe.Alegias + "\n";
            expedientesEnRango += "Enfermedades Base: " + expe.enfermedadesBase + "\n";
            expedientesEnRango += "Fecha de Cita: " + expe.FechaCita + "\n";
            expedientesEnRango += "Síntomas: " + expe.Sintomas + "\n";
            expedientesEnRango += "Observaciones: " + expe.Observaciones + "\n";
            expedientesEnRango += "Diagnóstico: " + expe.diagnostico + "\n";
            expedientesEnRango += "Recomendaciones: " + expe.Recomendaciones + "\n";
            expedientesEnRango += "Nueva Cita: " + expe.newCita + "\n";
            expedientesEnRango += "Comentarios Adicionales: " + expe.adicionalComents + "\n\n";
        }
    }
    if(expedientesEnRango==" "){
        expedientesEnRango= "No se han encotrado expedientes en las fechas seleccionada.";
    }
    return expedientesEnRango;
}


