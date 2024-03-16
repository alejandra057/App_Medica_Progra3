#include "admincodes.h"

#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QTextStream>
//
    //long codigoUser;
    //long codigoExpedientes;
    //long codigoSala;
    //long codigoPaciente;
//pa windows
//QFile AdministradorCodigos("AdministradorCodigos.itn");
//pa kenny
QFile AdministradorCodigos("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/AdministradorCodigos.itn");
QDataStream administrador (&AdministradorCodigos);

AdminCodes::AdminCodes() {
    AdministradorCodigos.open(QIODevice::ReadWrite);
    if (AdministradorCodigos.size()==0)
    {
        AdminDeCode codes;
         codes.codigoUser=0;
         codes.codigoExpedientes=0;
         codes.codigoSala=0;
         codes.codigoPaciente=0;
         AdministradorCodigos.seek(0);
         administrador << static_cast<qint64>(codes.codigoUser)
                       << static_cast<qint64>(codes.codigoExpedientes)
                       << static_cast<qint64>(codes.codigoSala)
                       << static_cast<qint64>(codes.codigoPaciente);
         AdministradorCodigos.flush();
    }
    if(!AdministradorCodigos.isOpen())
    {
        exit(0);
    }
}

long AdminCodes::NextCodigoUser()
{
    AdministradorCodigos.seek(0);
    qint64 codigoUser, codigoExpedientes, codigoSala, codigoPaciente;
    administrador >> codigoUser >> codigoExpedientes >> codigoSala >> codigoPaciente;

    long codigoUserLong = static_cast<long>(codigoUser);

    long nuevocodigoUserLong=codigoUserLong+1;
    long codigoExpedientesLong = static_cast<long>(codigoExpedientes);
    long codigoSalaLong = static_cast<long>(codigoSala);
    long codigoPacienteLong = static_cast<long>(codigoPaciente);

    AdministradorCodigos.seek(0);
    administrador << static_cast<qint64>(nuevocodigoUserLong)
                  << static_cast<qint64>(codigoExpedientesLong)
                  << static_cast<qint64>(codigoSalaLong)
                  << static_cast<qint64>(codigoPacienteLong);
    AdministradorCodigos.flush();
    return codigoUserLong;
}

long AdminCodes::NextcodigoExpedientes()
{
    AdministradorCodigos.seek(0);
    qint64 codigoUser, codigoExpedientes, codigoSala, codigoPaciente;

    administrador >> codigoUser >> codigoExpedientes >> codigoSala >> codigoPaciente;


    long codigoExpedientesLong = static_cast<long>(codigoExpedientes);
    AdministradorCodigos.seek(0);
    long nuevocodigoExpedientesLong= codigoExpedientesLong+1;
    long codigoUserLong = static_cast<long>(codigoUser);
    long codigoSalaLong = static_cast<long>(codigoSala);
    long codigoPacienteLong = static_cast<long>(codigoPaciente);
    administrador << static_cast<qint64>(codigoUserLong)
                  << static_cast<qint64>(nuevocodigoExpedientesLong)
                  << static_cast<qint64>(codigoSalaLong)
                  << static_cast<qint64>(codigoPacienteLong);
    AdministradorCodigos.flush();
    return codigoExpedientesLong;
}

long AdminCodes::NextcodigoSala()
{
    AdministradorCodigos.seek(0);
    qint64 codigoUser, codigoExpedientes, codigoSala, codigoPaciente;

    administrador >> codigoUser >> codigoExpedientes >> codigoSala >> codigoPaciente;

    long codigoSalaLong = static_cast<long>(codigoSala);

    AdministradorCodigos.seek(0);

    long nuevocodigoSalaLong=codigoSalaLong+1;
    long codigoUserLong = static_cast<long>(codigoUser);
    long codigoExpedientesLong = static_cast<long>(codigoExpedientes);
    long codigoPacienteLong = static_cast<long>(codigoPaciente);
    administrador << static_cast<qint64>(codigoUserLong)
                  << static_cast<qint64>(codigoExpedientesLong)
                  << static_cast<qint64>(nuevocodigoSalaLong)
                  << static_cast<qint64>(codigoPacienteLong);
    AdministradorCodigos.flush();
    return codigoSalaLong;
}

long AdminCodes::NextcodigoPaciente()
{
    AdministradorCodigos.seek(0);
    qint64 codigoUser, codigoExpedientes, codigoSala, codigoPaciente;
    administrador >> codigoUser >> codigoExpedientes >> codigoSala >> codigoPaciente;

    AdministradorCodigos.seek(0);

    long codigoPacienteLong = static_cast<long>(codigoPaciente);

    long nuevocodigoPacienteLong=codigoPacienteLong+1;
    long codigoUserLong = static_cast<long>(codigoUser);
    long codigoExpedientesLong = static_cast<long>(codigoExpedientes);
    long codigoSalaLong = static_cast<long>(codigoSala);

    administrador << static_cast<qint64>(codigoUserLong)
                  << static_cast<qint64>(codigoExpedientesLong)
                  << static_cast<qint64>(codigoSalaLong)
                  << static_cast<qint64>(nuevocodigoPacienteLong);
    AdministradorCodigos.flush();
    return codigoPacienteLong;
}
