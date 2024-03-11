#ifndef ADMINSALAS_H
#define ADMINSALAS_H

#include <string>
#include <QDate>

class adminSalas
{
    struct Sala {
        int code;
        QString description;
        QString status;
        QDate fechaInicio;
        QDate fechaDisponibilidad;
    };
public:
    adminSalas();
    bool addSala(std::string description, std::string status, QDate fechaInicio, QDate fechaDisponibilidad);
    bool modificarSala(int codigo, std::string description, std::string status, QDate fechaInicio, QDate fechaDisponibilidad);
    bool eliminarSala(int codigo);
private:
    int getSalaCode(long offset);
};

#endif // ADMINSALAS_H
