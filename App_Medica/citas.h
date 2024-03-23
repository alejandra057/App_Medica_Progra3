#ifndef CITAS_H
#define CITAS_H
#include <QString>
#include <QDate>
#include <QTime>
class Citas
{
    public:
    struct Datoscitas
    {
        QString code="";
        QString nombre="";
        QString fecha="";
        QString hora="";
    };



    Citas();

    bool CrearCitas(QString code,QString nombre, QString fecha, QString hora);
    bool ModificarCitas(QString code,QString nombre, QString fecha, QString hora);
    bool EliminarCitas(QString cita);
    QString ConsultarCitas(QString cita);
    Datoscitas buscarcita(QString code);
    Datoscitas Consultaporfecha(QString fecha);
    QString ConvertirDatosCitaAString(const Datoscitas& datos);
    long getCita_Actal();
    QString getCitasEnRango(QString fechaInicio, QString fechaFin);

    Datoscitas obtenerCitas() const{
        return citass;
    }

   /* QString obtenertexto() const{
        return citass;
    }*/


    void ModificarCitas(const Datoscitas& nuevacita){
        citass=nuevacita;
    }

private:
    Datoscitas citass;
};

#endif // CITAS_H
