#ifndef ADMINCODES_H
#define ADMINCODES_H

class AdminCodes
{
    struct AdminDeCode{
        long codigoUser;
        long codigoExpedientes;
        long codigoSala;
        long codigoPaciente;
    };
public:
    AdminCodes();

    long NextCodigoUser();

    long NextcodigoExpedientes();

    long NextcodigoSala();

    long NextcodigoPaciente();
};

#endif // ADMINCODES_H
