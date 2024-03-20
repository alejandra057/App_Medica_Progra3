#include "recetas.h"
#include "adminexpedientes.h"
#include <QDateTime>
#include <QMessageBox>
#include "admincodes.h"
/*QFile Recetas("Recetas.arc");
//QFile ExpedientesAdmin("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/Reservas.itn");
QDataStream escribir (&Recetas);
Recetas::Recetas()
{
    Recetas.open(QIODevice::ReadWrite);
    if(!Recetas.isOpen())
    {
        exit(0);
    }
}
*/
/*bool Recetas::newRecipe(QString code,QString numsala, QString nombre, QString Fecha, QString horainicio, QString horafinal, QString namedoctor, QString observaciones)
{
    AdminCodes codes;
    AdminExpedientes expedientes;
    QFile Expedientes("Expedientes.itn");
    if (!Expedientes.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(nullptr, "Error", "No se pudo abrir el archivo de expedientes");
        return false;
    }
    QDataStream leer(&Room);
    while (!leer.atEnd())
    {
        AdminExpedientes::NewExpediente expedientes = expedientes
                                                          leer >> ;
        if (Expedientes.paciente == paciente);
        {


            if (fecha >= fechaInicio && fecha <= fechaFin)
            {
                STReservaciones reservar;
                reservar.code = code;
                reservar.nombre = nombre;
                reservar.fecha = Fecha;
                reservar.horainicio = horainicio;
                reservar.horafinal = horafinal;
                reservar.namedoctor = namedoctor;
                reservar.observacion = observaciones;

                Reservaciones.seek(Reservaciones.size());
                writee << reservar.code << reservar.nombre << reservar.fecha << reservar.horainicio << reservar.horafinal << reservar.namedoctor << reservar.observacion;
                Reservaciones.flush();
                return true;
            } else {
                Room.close();
                QMessageBox::information(nullptr, "Error", "Fecha no disponible");
                return false;
            }
        }
    }
    QMessageBox::information(nullptr, "Error", "No se ");

    return false;
}
*/

bool Recetas::crearNuevaReceta(long code, const QStringList &medicamento, const QString &dosis)
{
    QFile file("Recetas.itn");
    if (!file.open(QIODevice::Append)) {
        // Error al abrir el archivo
        qDebug() << "Error al abrir el archivo Recetas.itn";
        return false;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_0);

    out << static_cast<qint64>(code); // Convertir el código de receta a qint64 antes de escribirlo
    out << medicamento;
    out << dosis;
    out << QDate::currentDate();

    file.close();

    return true;


}
