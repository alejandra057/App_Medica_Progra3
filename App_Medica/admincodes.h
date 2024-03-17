#ifndef ADMINCODES_H
#define ADMINCODES_H

class AdminCodes
{
    struct AdminDeCode{
        long codigoUser;
        long codigoExpedientes;
        long codigoSala;
        long codigoPaciente;
        long codigoReservaciones;
        long codigoCitas;
    };
public:
    AdminCodes();

    long NextCodigoUser();

    long NextcodigoExpedientes();

    long NextcodigoSala();

    long NextcodigoPaciente();

    long NextcodigoReservas();

    long NextcodigoCitas();

    long GetActualCodeSalas();

};

#endif // ADMINCODES_H
