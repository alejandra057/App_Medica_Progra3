#ifndef ADMINROLES_H
#define ADMINROLES_H
#include <QString>
#include <QFile>
#include <QDataStream>
class adminRoles
{
public:
    adminRoles();
    bool addRole(QString Role);
    QString showRoles();
};

#endif // ADMINROLES_H
