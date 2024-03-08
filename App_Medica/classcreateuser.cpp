#include "classcreateuser.h"

//para los archivos
#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QTextStream>
#include <iostream>

QFile UserAdmin("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/User.itn");
QDataStream writeandwrite (&UserAdmin);
bool boleano=true;

classcreateuser::classcreateuser() {
    UserAdmin.open(QIODevice::ReadWrite);

    if (UserAdmin.size()==0){
        UserAdmin.seek(0);
        writeandwrite <<"admin"<<"admin"<<"admin"<<"admin"<<boleano;
        UserAdmin.flush();
    }
    if(!UserAdmin.isOpen()){
        exit(0);
    }
}

QString classcreateuser::readuser(QString password, QString cuenta)
{
    return password+" "+cuenta;
}

bool classcreateuser::CreateUserFun(QString nombre, QString password, QString cuenta, QString rol, bool status)
{
    CrearUserFormat create;
    create.nombre = nombre;
    create.password = password;
    create.cuenta = cuenta;
    create.rol = rol;
    create.status = status;
    UserAdmin.seek(UserAdmin.size());
    writeandwrite << create.nombre << create.password << create.cuenta << create.rol << create.status;
    UserAdmin.flush();
    return true;
}

bool classcreateuser::EditUser(QString nombre, QString cuenta)
{
    long save = 0;
    UserAdmin.seek(0);
    while (!UserAdmin.atEnd()) {
        CrearUserFormat create;
        create.nombre = nombre;
        create.password = "password";
        create.cuenta = cuenta;
        create.rol = "rol";
        create.status = false;
        save = UserAdmin.pos();
        writeandwrite >> create.nombre >> create.password >> create.cuenta >> create.rol >> create.status;
        if (create.nombre == nombre && create.cuenta == cuenta) {
            UserAdmin.seek(save);

            writeandwrite << create.nombre << create.password << create.cuenta << create.rol << create.status;
            return true;
        }
    }
    return false;
}

QString classcreateuser::BuscarUser(QString cuenta, QString password)
{
    CrearUserFormat create;
    QString Usercuenta;
    QString UserPassword;
    UserAdmin.seek(0);
    while (!UserAdmin.atEnd()) {
    writeandwrite >> create.nombre >> UserPassword >> Usercuenta >> create.rol >> create.status;
        readuser(Usercuenta,UserPassword);
        if (Usercuenta == cuenta && UserPassword == password) {
            UserAdmin.seek(0);
            return UserPassword+" "+Usercuenta;
        }
        return UserPassword+" "+Usercuenta;
    }
    return UserPassword+" "+Usercuenta;
}


