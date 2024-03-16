#include "adminroles.h"
#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QTextStream>
//pa kenny
QFile AdminRoles("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/RolesAdmin.itn");
QFile Privilegio("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/PrivilegiosRoles.itn");
//pa ustedes

QDataStream Roles (&AdminRoles);
QDataStream privilegios(&Privilegio);
adminRoles::adminRoles() {
    AdminRoles.open(QIODevice::ReadWrite);
    Privilegio.open(QIODevice::ReadWrite);

    if(!Privilegio.isOpen())
    {
        exit(0);
    }
    if (AdminRoles.size()==0){
        adminRoles::addRole("admin");
        AdminRoles.flush();
    }

    if(!AdminRoles.isOpen())
    {
        exit(0);
    }
}


bool adminRoles::addRole(QString Role)
{
    AdminRoles.seek(AdminRoles.size());
    Roles <<Role;
    AdminRoles.flush();
    return true;
}

QString adminRoles::showRoles()
{

}
