#include "adminroles.h"
#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QTextStream>
//pa kenny
QFile AdminRoles("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/RolesAdmin.itn");
QFile Privilegio("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/PrivilegiosRoles.itn");
//pa ustedes
//QFile AdminRoles("RolesAdmin.itn");
//QFile Privilegio("PrivilegiosRoles.itn");
//pa ustedes
QDataStream Roles (&AdminRoles);
QDataStream privilegios(&Privilegio);
long bytesA;
adminRoles::adminRoles() {
    AdminRoles.open(QIODevice::ReadWrite);
    Privilegio.open(QIODevice::ReadWrite);
    bytesA=0;
    if(!Privilegio.isOpen())
    {
        exit(0);
    }
    if (AdminRoles.size()==0){
        adminRoles::addRole("admin",true, true, true, true, true, true, true, true, true, true, true,true,true);
        adminRoles::addRole("Doctor",false, true, true, true, true, true, true, true, true, true, true,true,true);
        adminRoles::addRole("Enfermera",false, true, true, true, true, false, true, false, false, true, true,true,true);
        AdminRoles.flush();
    }

    if(!AdminRoles.isOpen())
    {
        exit(0);
    }
}


bool adminRoles::addRole(QString Role, bool crearUser, bool crearExpedientes, bool crearSalas, bool editarSalas, bool deshabilitarSalas, bool editarExpedientes, bool InformacionConvencional, bool crearRecetas, bool editarRecetas, bool agendarConsultas, bool verReportes, bool verReservaciones, bool verCitas)
{
    AdminRoles.seek(AdminRoles.size());
    Roles <<Role << crearUser << crearExpedientes << crearSalas << editarSalas << deshabilitarSalas << editarExpedientes << InformacionConvencional << crearRecetas << editarRecetas << agendarConsultas << verReportes << verReservaciones << verCitas;
    AdminRoles.flush();
    return true;
}

QString adminRoles::showRoles()
{
    AdminRoles.seek(bytesA);
    QString Role;
    bool crearUser;
    bool crearExpedientes;
    bool crearSalas;
    bool editarSalas;
    bool deshabilitarSalas;
    bool editarExpedientes;
    bool InformacionConvencional;
    bool crearRecetas;
    bool editarRecetas;
    bool agendarConsultas;
    bool verReportes;
    bool verReservaciones;
    bool verCitas;
    Roles >>Role >> crearUser >> crearExpedientes >> crearSalas >> editarSalas >> deshabilitarSalas >> editarExpedientes >> InformacionConvencional >> crearRecetas >> editarRecetas >> agendarConsultas >> verReportes >> verReservaciones >> verCitas;

    bytesA=AdminRoles.pos();
    return Role;
}

long adminRoles::cantRoles()
{
    AdminRoles.seek(0);
    long cantidadRoles=0;
    QString Role;
    bool crearUser;
    bool crearExpedientes;
    bool crearSalas;
    bool editarSalas;
    bool deshabilitarSalas;
    bool editarExpedientes;
    bool InformacionConvencional;
    bool crearRecetas;
    bool editarRecetas;
    bool agendarConsultas;
    bool verReportes;
    bool verReservaciones;
    bool verCitas;

    while(!AdminRoles.atEnd()){
        Roles >>Role >> crearUser >> crearExpedientes >> crearSalas >> editarSalas >> deshabilitarSalas >> editarExpedientes >> InformacionConvencional >> crearRecetas >> editarRecetas >> agendarConsultas >> verReportes >> verReservaciones >> verCitas;
        cantidadRoles++;
    }

    return cantidadRoles;
}

bool adminRoles::permisoAdministrarUser(QString Role)
{
    AdminRoles.seek(0);

    QString RoleUser;
    bool crearUser;
    bool crearExpedientes;
    bool crearSalas;
    bool editarSalas;
    bool deshabilitarSalas;
    bool editarExpedientes;
    bool InformacionConvencional;
    bool crearRecetas;
    bool editarRecetas;
    bool agendarConsultas;
    bool verReportes;
    bool verReservaciones;
    bool verCitas;

    while (!AdminRoles.atEnd()) {
        Roles >> RoleUser >> crearUser >> crearExpedientes >> crearSalas >> editarSalas >> deshabilitarSalas >> editarExpedientes >> InformacionConvencional >> crearRecetas >> editarRecetas >> agendarConsultas >> verReportes >> verReservaciones >>verCitas;
        if (Role == RoleUser) {
            if (crearUser) {
                return true;
            }
        }
    }

    return false;
}

bool adminRoles::permisoCrearExpedientes(QString Role)
{
    AdminRoles.seek(0);

    QString RoleUser;
    bool crearUser;
    bool crearExpedientes;
    bool crearSalas;
    bool editarSalas;
    bool deshabilitarSalas;
    bool editarExpedientes;
    bool InformacionConvencional;
    bool crearRecetas;
    bool editarRecetas;
    bool agendarConsultas;
    bool verReportes;
    bool verReservaciones;
    bool verCitas;

    while (!AdminRoles.atEnd()) {
        Roles >> RoleUser >> crearUser >> crearExpedientes >> crearSalas >> editarSalas >> deshabilitarSalas >> editarExpedientes >> InformacionConvencional >> crearRecetas >> editarRecetas >> agendarConsultas >> verReportes >> verReservaciones >>verCitas;
        if (Role == RoleUser) {
            if (crearExpedientes) {
                return true;
            }
        }
    }

    return false;
}

bool adminRoles::permisoCrearSala(QString Role)
{
    AdminRoles.seek(0);

    QString RoleUser;
    bool crearUser;
    bool crearExpedientes;
    bool crearSalas;
    bool editarSalas;
    bool deshabilitarSalas;
    bool editarExpedientes;
    bool InformacionConvencional;
    bool crearRecetas;
    bool editarRecetas;
    bool agendarConsultas;
    bool verReportes;
    bool verReservaciones;
    bool verCitas;
    while (!AdminRoles.atEnd()) {
        Roles >> RoleUser >> crearUser >> crearExpedientes >> crearSalas >> editarSalas >> deshabilitarSalas >> editarExpedientes >> InformacionConvencional >> crearRecetas >> editarRecetas >> agendarConsultas >> verReportes >> verReservaciones >>verCitas;
        if (Role == RoleUser) {
            if (crearSalas) {
                return true;
            }
        }
    }

    return false;
}

bool adminRoles::permisoEditarSala(QString Role)
{
    AdminRoles.seek(0);

    QString RoleUser;
    bool crearUser;
    bool crearExpedientes;
    bool crearSalas;
    bool editarSalas;
    bool deshabilitarSalas;
    bool editarExpedientes;
    bool InformacionConvencional;
    bool crearRecetas;
    bool editarRecetas;
    bool agendarConsultas;
    bool verReportes;
    bool verReservaciones;
    bool verCitas;
    while (!AdminRoles.atEnd()) {
        Roles >> RoleUser >> crearUser >> crearExpedientes >> crearSalas >> editarSalas >> deshabilitarSalas >> editarExpedientes >> InformacionConvencional >> crearRecetas >> editarRecetas >> agendarConsultas >> verReportes >> verReservaciones >>verCitas;
        if (Role == RoleUser) {
            if (editarSalas) {
                return true;
            }
        }
    }

    return false;
}

bool adminRoles::permisoDesabilitarSala(QString Role)
{
    AdminRoles.seek(0);

    QString RoleUser;
    bool crearUser;
    bool crearExpedientes;
    bool crearSalas;
    bool editarSalas;
    bool deshabilitarSalas;
    bool editarExpedientes;
    bool InformacionConvencional;
    bool crearRecetas;
    bool editarRecetas;
    bool agendarConsultas;
    bool verReportes;
    bool verReservaciones;
    bool verCitas;
    while (!AdminRoles.atEnd()) {
        Roles >> RoleUser >> crearUser >> crearExpedientes >> crearSalas >> editarSalas >> deshabilitarSalas >> editarExpedientes >> InformacionConvencional >> crearRecetas >> editarRecetas >> agendarConsultas >> verReportes >> verReservaciones >>verCitas;
        if (Role == RoleUser) {
            if (deshabilitarSalas) {
                return true;
            }
        }
    }

    return false;
}

bool adminRoles::permisoEditarExpediente(QString Role)
{
    AdminRoles.seek(0);

    QString RoleUser;
    bool crearUser;
    bool crearExpedientes;
    bool crearSalas;
    bool editarSalas;
    bool deshabilitarSalas;
    bool editarExpedientes;
    bool InformacionConvencional;
    bool crearRecetas;
    bool editarRecetas;
    bool agendarConsultas;
    bool verReportes;
    bool verReservaciones;
    bool verCitas;
    while (!AdminRoles.atEnd()) {
        Roles >> RoleUser >> crearUser >> crearExpedientes >> crearSalas >> editarSalas >> deshabilitarSalas >> editarExpedientes >> InformacionConvencional >> crearRecetas >> editarRecetas >> agendarConsultas >> verReportes >> verReservaciones >>verCitas;
        if (Role == RoleUser) {
            if (editarExpedientes) {
                return true;
            }
        }
    }

    return false;
}

bool adminRoles::permisoInformacion(QString Role)
{
    AdminRoles.seek(0);

    QString RoleUser;
    bool crearUser;
    bool crearExpedientes;
    bool crearSalas;
    bool editarSalas;
    bool deshabilitarSalas;
    bool editarExpedientes;
    bool InformacionConvencional;
    bool crearRecetas;
    bool editarRecetas;
    bool agendarConsultas;
    bool verReportes;
    bool verReservaciones;
    bool verCitas;

    while (!AdminRoles.atEnd()) {
        Roles >> RoleUser >> crearUser >> crearExpedientes >> crearSalas >> editarSalas >> deshabilitarSalas >> editarExpedientes >> InformacionConvencional >> crearRecetas >> editarRecetas >> agendarConsultas >> verReportes >>verReservaciones >>verCitas;
        if (Role == RoleUser) {
            if (InformacionConvencional) {
                return true;
            }
        }
    }

    return false;
}

bool adminRoles::permisoCrearRecetas(QString Role)
{
    AdminRoles.seek(0);

    QString RoleUser;
    bool crearUser;
    bool crearExpedientes;
    bool crearSalas;
    bool editarSalas;
    bool deshabilitarSalas;
    bool editarExpedientes;
    bool InformacionConvencional;
    bool crearRecetas;
    bool editarRecetas;
    bool agendarConsultas;
    bool verReportes;
    bool verReservaciones;
    bool verCitas;

    while (!AdminRoles.atEnd()) {
        Roles >> RoleUser >> crearUser >> crearExpedientes >> crearSalas >> editarSalas >> deshabilitarSalas >> editarExpedientes >> InformacionConvencional >> crearRecetas >> editarRecetas >> agendarConsultas >> verReportes >> verReservaciones >>verCitas;
        if (Role == RoleUser) {
            if (crearRecetas) {
                return true;
            }
        }
    }

    return false;
}

bool adminRoles::permisoEditarRecetas(QString Role)
{
    AdminRoles.seek(0);

    QString RoleUser;
    bool crearUser;
    bool crearExpedientes;
    bool crearSalas;
    bool editarSalas;
    bool deshabilitarSalas;
    bool editarExpedientes;
    bool InformacionConvencional;
    bool crearRecetas;
    bool editarRecetas;
    bool agendarConsultas;
    bool verReportes;
    bool verReservaciones;
    bool verCitas;

    while (!AdminRoles.atEnd()) {
        Roles >> RoleUser >> crearUser >> crearExpedientes >> crearSalas >> editarSalas >> deshabilitarSalas >> editarExpedientes >> InformacionConvencional >> crearRecetas >> editarRecetas >> agendarConsultas >> verReportes >>verReservaciones >>verCitas;
        if (Role == RoleUser) {
            if (editarRecetas) {
                return true;
            }
        }
    }

    return false;
}

bool adminRoles::permisoAgendaConsultas(QString Role)
{
    AdminRoles.seek(0);

    QString RoleUser;
    bool crearUser;
    bool crearExpedientes;
    bool crearSalas;
    bool editarSalas;
    bool deshabilitarSalas;
    bool editarExpedientes;
    bool InformacionConvencional;
    bool crearRecetas;
    bool editarRecetas;
    bool agendarConsultas;
    bool verReportes;
    bool verReservaciones;
    bool verCitas;

    while (!AdminRoles.atEnd()) {
        Roles >> RoleUser >> crearUser >> crearExpedientes >> crearSalas >> editarSalas >> deshabilitarSalas >> editarExpedientes >> InformacionConvencional >> crearRecetas >> editarRecetas >> agendarConsultas >> verReportes >>verReservaciones >>verCitas;
        if (Role == RoleUser) {
            if (agendarConsultas) {
                return true;
            }
        }
    }

    return false;
}

bool adminRoles::permisoVerReportes(QString Role)
{
    AdminRoles.seek(0);

    QString RoleUser;
    bool crearUser;
    bool crearExpedientes;
    bool crearSalas;
    bool editarSalas;
    bool deshabilitarSalas;
    bool editarExpedientes;
    bool InformacionConvencional;
    bool crearRecetas;
    bool editarRecetas;
    bool agendarConsultas;
    bool verReportes;
    bool verReservaciones;
    bool verCitas;

    while (!AdminRoles.atEnd()) {
        Roles >> RoleUser >> crearUser >> crearExpedientes >> crearSalas >> editarSalas >> deshabilitarSalas >> editarExpedientes >> InformacionConvencional >> crearRecetas >> editarRecetas >> agendarConsultas >> verReportes >> verReservaciones >>verCitas;
        if (Role == RoleUser) {
            if (verReportes) {
                return true;
            }
        }
    }

    return false;
}

bool adminRoles::permisoReservaciones(QString Role)
{
    AdminRoles.seek(0);

    QString RoleUser;
    bool crearUser;
    bool crearExpedientes;
    bool crearSalas;
    bool editarSalas;
    bool deshabilitarSalas;
    bool editarExpedientes;
    bool InformacionConvencional;
    bool crearRecetas;
    bool editarRecetas;
    bool agendarConsultas;
    bool verReportes;
    bool verReservaciones;
    bool verCitas;

    while (!AdminRoles.atEnd()) {
        Roles >> RoleUser >> crearUser >> crearExpedientes >> crearSalas >> editarSalas >> deshabilitarSalas >> editarExpedientes >> InformacionConvencional >> crearRecetas >> editarRecetas >> agendarConsultas >> verReportes >> verReservaciones >> verCitas;
        if (Role == RoleUser) {
            if (verReservaciones) {
                return true;
            }
        }
    }

    return false;
}

bool adminRoles::permisoCita(QString Role)
{
    AdminRoles.seek(0);

    QString RoleUser;
    bool crearUser;
    bool crearExpedientes;
    bool crearSalas;
    bool editarSalas;
    bool deshabilitarSalas;
    bool editarExpedientes;
    bool InformacionConvencional;
    bool crearRecetas;
    bool editarRecetas;
    bool agendarConsultas;
    bool verReportes;
    bool verReservaciones;
    bool verCitas;

    while (!AdminRoles.atEnd()) {
        Roles >> RoleUser >> crearUser >> crearExpedientes >> crearSalas >> editarSalas >> deshabilitarSalas >> editarExpedientes >> InformacionConvencional >> crearRecetas >> editarRecetas >> agendarConsultas >> verReportes >> verReservaciones >> verCitas;
        if (Role == RoleUser) {
            if (verCitas) {
                return true;
            }
        }
    }

    return false;
}
