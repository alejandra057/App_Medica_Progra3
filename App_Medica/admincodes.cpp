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
QFile AdministradorCodigos("AdministradorCodigos.itn");
//pa kenny
//QFile AdministradorCodigos("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/AdministradorCodigos.itn");
QDataStream administrador (&AdministradorCodigos);

AdminCodes::AdminCodes() {
    AdministradorCodigos.open(QIODevice::ReadWrite);
    if (AdministradorCodigos.size()==0)
    {
        AdminDeCode codes;
         codes.codigoUser=1;
         codes.codigoExpedientes=1;
         codes.codigoSala=1;
         codes.codigoPaciente=1;
         codes.codigoReservaciones=0;
         codes.codigoCitas=1;
         AdministradorCodigos.seek(0);
         administrador << static_cast<qint64>(codes.codigoUser)
                       << static_cast<qint64>(codes.codigoExpedientes)
                       << static_cast<qint64>(codes.codigoSala)
                       << static_cast<qint64>(codes.codigoPaciente)
                       << static_cast<qint64>(codes.codigoReservaciones)
                       << static_cast<qint64>(codes.codigoCitas);
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
    qint64 codigoUser, codigoExpedientes, codigoSala, codigoPaciente, codigoReservaciones, codigoCitas;
    administrador >> codigoUser >> codigoExpedientes >> codigoSala >> codigoPaciente >> codigoReservaciones >> codigoCitas;

    long codigoUserLong = static_cast<long>(codigoUser);

    long nuevocodigoUserLong=codigoUserLong+1;
    long codigoExpedientesLong = static_cast<long>(codigoExpedientes);
    long codigoSalaLong = static_cast<long>(codigoSala);
    long codigoPacienteLong = static_cast<long>(codigoPaciente);
    long codigoReservasLong = static_cast<long>(codigoReservaciones);
    long codigoCitasLong = static_cast<long>(codigoCitas);
    AdministradorCodigos.seek(0);
    administrador << static_cast<qint64>(nuevocodigoUserLong)
                  << static_cast<qint64>(codigoExpedientesLong)
                  << static_cast<qint64>(codigoSalaLong)
                  << static_cast<qint64>(codigoPacienteLong)
                  << static_cast<qint64>(codigoReservasLong)
                  << static_cast<qint64>(codigoCitasLong);
    AdministradorCodigos.flush();
    return codigoUserLong;
}

long AdminCodes::NextcodigoExpedientes()
{
    AdministradorCodigos.seek(0);
    qint64 codigoUser, codigoExpedientes, codigoSala, codigoPaciente, codigoReservaciones, codigoCitas;
    administrador >> codigoUser >> codigoExpedientes >> codigoSala >> codigoPaciente >> codigoReservaciones >> codigoCitas;


    long codigoExpedientesLong = static_cast<long>(codigoExpedientes);
    AdministradorCodigos.seek(0);
    long nuevocodigoExpedientesLong= codigoExpedientesLong+1;
    long codigoUserLong = static_cast<long>(codigoUser);
    long codigoSalaLong = static_cast<long>(codigoSala);
    long codigoPacienteLong = static_cast<long>(codigoPaciente);
    long codigoReservasLong = static_cast<long>(codigoReservaciones);
    long codigoCitasLong = static_cast<long>(codigoCitas);
    administrador << static_cast<qint64>(codigoUserLong)
                  << static_cast<qint64>(nuevocodigoExpedientesLong)
                  << static_cast<qint64>(codigoSalaLong)
                  << static_cast<qint64>(codigoPacienteLong)
                  << static_cast<qint64>(codigoReservasLong)
                  << static_cast<qint64>(codigoCitasLong);
    AdministradorCodigos.flush();
    return codigoExpedientesLong;
}

long AdminCodes::NextcodigoSala()
{
    AdministradorCodigos.seek(0);
    qint64 codigoUser, codigoExpedientes, codigoSala, codigoPaciente, codigoReservaciones, codigoCitas;
    administrador >> codigoUser >> codigoExpedientes >> codigoSala >> codigoPaciente >> codigoReservaciones >> codigoCitas;


    long codigoSalaLong = static_cast<long>(codigoSala);

    AdministradorCodigos.seek(0);

    long nuevocodigoSalaLong=codigoSalaLong+1;
    long codigoUserLong = static_cast<long>(codigoUser);
    long codigoExpedientesLong = static_cast<long>(codigoExpedientes);
    long codigoPacienteLong = static_cast<long>(codigoPaciente);
    long codigoReservasLong = static_cast<long>(codigoReservaciones);
    long codigoCitasLong = static_cast<long>(codigoCitas);
    administrador << static_cast<qint64>(codigoUserLong)
                  << static_cast<qint64>(codigoExpedientesLong)
                  << static_cast<qint64>(nuevocodigoSalaLong)
                  << static_cast<qint64>(codigoPacienteLong)
                  << static_cast<qint64>(codigoReservasLong)
                  << static_cast<qint64>(codigoCitasLong);
    AdministradorCodigos.flush();
    return codigoSalaLong;
}

long AdminCodes::NextcodigoPaciente()
{
    AdministradorCodigos.seek(0);
    qint64 codigoUser, codigoExpedientes, codigoSala, codigoPaciente, codigoReservaciones, codigoCitas;
    administrador >> codigoUser >> codigoExpedientes >> codigoSala >> codigoPaciente >> codigoReservaciones >> codigoCitas;

    AdministradorCodigos.seek(0);

    long codigoPacienteLong = static_cast<long>(codigoPaciente);

    long nuevocodigoPacienteLong=codigoPacienteLong+1;
    long codigoUserLong = static_cast<long>(codigoUser);
    long codigoExpedientesLong = static_cast<long>(codigoExpedientes);
    long codigoSalaLong = static_cast<long>(codigoSala);
    long codigoReservasLong = static_cast<long>(codigoReservaciones);
    long codigoCitasLong = static_cast<long>(codigoCitas);
    administrador << static_cast<qint64>(codigoUserLong)
                  << static_cast<qint64>(codigoExpedientesLong)
                  << static_cast<qint64>(codigoSalaLong)
                  << static_cast<qint64>(nuevocodigoPacienteLong)
                  << static_cast<qint64>(codigoReservasLong)
                  << static_cast<qint64>(codigoCitasLong);
    AdministradorCodigos.flush();
    return codigoPacienteLong;
}

long AdminCodes::NextcodigoReservas()
{
    AdministradorCodigos.seek(0);
    qint64 codigoUser, codigoExpedientes, codigoSala, codigoPaciente, codigoReservaciones, codigoCitas;
    administrador >> codigoUser >> codigoExpedientes >> codigoSala >> codigoPaciente >> codigoReservaciones >> codigoCitas;

    AdministradorCodigos.seek(0);

    long codigoReservasLong = static_cast<long>(codigoReservaciones);
    long nuevocodigoreservasLong=codigoReservasLong+1;

    long codigoUserLong = static_cast<long>(codigoUser);
    long codigoExpedientesLong = static_cast<long>(codigoExpedientes);
    long codigoSalaLong = static_cast<long>(codigoSala);
    long codigoPacienteLong = static_cast<long>(codigoPaciente);
    long codigoCitasLong = static_cast<long>(codigoCitas);
    administrador << static_cast<qint64>(codigoUserLong)
                  << static_cast<qint64>(codigoExpedientesLong)
                  << static_cast<qint64>(codigoSalaLong)
                  << static_cast<qint64>(codigoPacienteLong)
                  << static_cast<qint64>(nuevocodigoreservasLong)
                  << static_cast<qint64>(codigoCitasLong);

    AdministradorCodigos.flush();
    return nuevocodigoreservasLong;
}

long AdminCodes::NextcodigoCitas()
{
    AdministradorCodigos.seek(0);
    qint64 codigoUser, codigoExpedientes, codigoSala, codigoPaciente, codigoReservaciones, codigoCitas;
    administrador >> codigoUser >> codigoExpedientes >> codigoSala >> codigoPaciente >> codigoReservaciones >> codigoCitas;

    AdministradorCodigos.seek(0);

    long codigoCitasLong = static_cast<long>(codigoCitas);
    long nuevocodigocitasLong=codigoCitasLong+1;

    long codigoUserLong = static_cast<long>(codigoUser);
    long codigoExpedientesLong = static_cast<long>(codigoExpedientes);
    long codigoSalaLong = static_cast<long>(codigoSala);
    long codigoPacienteLong = static_cast<long>(codigoPaciente);
    long codigoReservasLong = static_cast<long>(codigoReservaciones);
    administrador << static_cast<qint64>(codigoUserLong)
                  << static_cast<qint64>(codigoExpedientesLong)
                  << static_cast<qint64>(codigoSalaLong)
                  << static_cast<qint64>(codigoPacienteLong)
                  << static_cast<qint64>(codigoReservasLong)
                  << static_cast<qint64>(nuevocodigocitasLong);

    AdministradorCodigos.flush();
    return nuevocodigocitasLong;
}
long AdminCodes :: GetActualCodeSalas(){
    AdministradorCodigos.seek(0);
    qint64 codigoUser, codigoExpedientes, codigoSala, codigoPaciente, codigoReservaciones, codigoCitas;
    administrador >> codigoUser >> codigoExpedientes >> codigoSala >> codigoPaciente >> codigoReservaciones >> codigoCitas;

    long codigoSalalong = static_cast<long>(codigoSala);

    return codigoSalalong;
}

long AdminCodes::GetActualCodeExpedientes()
{
    AdministradorCodigos.seek(0);
    qint64 codigoUser, codigoExpedientes, codigoSala, codigoPaciente, codigoReservaciones, codigoCitas;
    administrador >> codigoUser >> codigoExpedientes >> codigoSala >> codigoPaciente >> codigoReservaciones >> codigoCitas;

    long codigoExpedienteslong = static_cast<long>(codigoExpedientes);

    return codigoExpedienteslong;
}

long AdminCodes :: GetActualCodeCitas(){
    AdministradorCodigos.seek(0);
    qint64 codigoUser, codigoExpedientes, codigoSala, codigoPaciente, codigoReservaciones, codigoCitas;
    administrador >> codigoUser >> codigoExpedientes >> codigoSala >> codigoPaciente >> codigoReservaciones >> codigoCitas;

    long codigocitalong = static_cast<long>(codigoCitas);

    return codigocitalong;
}
