#include "classcreateuser.h"

//para los archivos
#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QTextStream>
//pa windows
//QFile UserAdmin("User.itn");
//pa kenny
QFile UserAdmin("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/User.itn");
QDataStream writeandwrite (&UserAdmin);
bool boleano=true;

classcreateuser::classcreateuser() {
    UserAdmin.open(QIODevice::ReadWrite);

    if (UserAdmin.size()==0){
        classcreateuser::CreateUserFun("admin", "admin", "admin", "admin", boleano);
    }
    if(!UserAdmin.isOpen()){
        exit(0);
    }
}

bool classcreateuser::CreateUserFun(QString nombre, QString password, QString cuenta, QString rol, bool status)
{
    CrearUserFormat create;
    create.nombre = nombre;
    create.password = "admin";
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
        create.password = "admin";
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

bool classcreateuser::BuscarUser(QString cuenta, QString password, QString name)
{
    CrearUserFormat create;
    QString Usercuenta;
    QString UserPassword;
    UserAdmin.seek(0);
    while (!UserAdmin.atEnd()) {
        writeandwrite >> create.nombre >> UserPassword >> Usercuenta >> create.rol >> create.status;
        if (Usercuenta == cuenta) {
            if(UserPassword == password || create.nombre==name){
                return true;
            }
        }
    }
    return false;
}

bool classcreateuser::CambiarStatus(QString name, QString cuenta)
{
    long save = 0;
    UserAdmin.seek(0);
    while (!UserAdmin.atEnd()) {
        CrearUserFormat create;
        create.status = true;
        save = UserAdmin.pos();
        writeandwrite >> create.nombre >> create.password >> create.cuenta >> create.rol >> create.status;
        if (create.nombre == name && create.cuenta == cuenta) {
            UserAdmin.seek(save);
            create.status = true;
            writeandwrite << create.nombre << create.password << create.cuenta << create.rol << create.status;
            return true;
        }
    }
    return false;
}
