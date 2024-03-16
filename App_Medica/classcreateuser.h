#ifndef CLASSCREATEUSER_H
#define CLASSCREATEUSER_H

//#include <string>
#include <QString>
// declarar string de la libreria standart
using namespace std;

class classcreateuser
{
    struct CrearUserFormat{
        //nombre, cuenta, rol, status
        QString nombre="";
        QString password = "user";
        QString cuenta="";
        QString rol="";
        bool status=true;
    };
public:
    classcreateuser();
    QString readuser(QString password, QString cuenta);
    bool CreateUserFun(QString nombre,QString password,QString cuenta,QString rol,bool status);
    bool EditUser(QString nombre,QString cuenta);
    bool BuscarUser(QString cuenta,QString password,QString name);
    bool CambiarStatus(QString name,QString cuenta);
};

#endif // CLASSCREATEUSER_H
