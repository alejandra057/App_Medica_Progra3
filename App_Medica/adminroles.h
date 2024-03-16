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

    };
public:
    adminRoles();
    bool addRole(QString Role);
    QString showRoles();
};

#endif // ADMINROLES_H
