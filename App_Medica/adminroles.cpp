#include "adminroles.h"
#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QTextStream>

QFile AdminRoles("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/Roles.itn");
QDataStream Roles (&AdminRoles);

adminRoles::adminRoles() {
    AdminRoles.open(QIODevice::ReadWrite);

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
