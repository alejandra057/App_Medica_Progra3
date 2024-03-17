#ifndef ADMINROLES_H
#define ADMINROLES_H
#include <QString>
#include <QFile>
#include <QDataStream>
class adminRoles
{
    struct  PermisosUser{
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
    };
public:
    adminRoles();
    bool addRole(QString Role, bool crearUser, bool crearExpedientes, bool crearSalas, bool editarSalas, bool deshabilitarSalas, bool editarExpedientes, bool InformacionConvencional, bool crearRecetas, bool editarRecetas, bool agendarConsultas, bool verReportes, bool verReservaciones,bool verCitas);
    QString showRoles();
    long cantRoles();
    bool permisoAdministrarUser(QString Role);
    bool permisoCrearExpedientes(QString Role);
    bool permisoCrearSala(QString Role);
    bool permisoEditarSala(QString Role);
    bool permisoDesabilitarSala(QString Role);
    bool permisoEditarExpediente(QString Role);
    bool permisoInformacion(QString Role);
    bool permisoCrearRecetas(QString Role);
    bool permisoEditarRecetas(QString Role);
    bool permisoAgendaConsultas(QString Role);
    bool permisoVerReportes(QString Role);
    bool permisoReservaciones(QString Role);
    bool permisoCita(QString Role);
};

#endif // ADMINROLES_H
