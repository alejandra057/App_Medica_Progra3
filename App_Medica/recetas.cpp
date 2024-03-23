#include "recetas.h"
#include "adminexpedientes.h"
#include <QDateTime>
#include <QMessageBox>
//QFile Recetas("Recetas.itn");
bool Recetas::crearNuevaReceta(long code, QString medicamento, QString dosis)
{
    QFile Recetas("Recetas.itn");
    //QFile Recetas("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/Recetas.itn");
    if (!Recetas.open(QIODevice::Append)) {
        return false; // No es necesario llamar a exit(0) aquí
    }

    QDataStream out(&Recetas);
    out.setVersion(QDataStream::Qt_5_0);

    out << static_cast<qint64>(code);
    out << medicamento;
    out << dosis;
    out << QDate::currentDate();
    Recetas.flush();

    return true;
}

QString Recetas::searchRecetaFecha(QString fechaB)
{
    QFile Recetas("Recetas.itn");
    //QFile Recetas("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/Recetas.itn");
    if (!Recetas.open(QIODevice::ReadOnly)) {
        return "No se puede abrir el archivo de recetas.";
    }

    QDataStream in(&Recetas);
    in.setVersion(QDataStream::Qt_5_0);

    QString result;
    bool found = false;
    long expe = 1; // Iniciar el número de expediente desde 1

    while (!in.atEnd()) {
        qint64 code;
        QString medicamento;
        QString dosis;
        QDate fecha;

        in >> code >> medicamento >> dosis >> fecha;

        if (fecha.toString("yyyy-MM-dd") == fechaB) {
            found = true;

            result += "---------------" + QString::number(expe) + "---------------\n";
            result += "Código: " + QString::number(code) + "\n";
            result += "Medicamento: " + medicamento + "\n";
            result += "Dosis: " + dosis + "\n";
            result += "Fecha: " + fecha.toString("yyyy-MM-dd") + "\n\n";
            expe++;
        }
    }

    if (!found) {
        result = "No se encontraron recetas para la fecha " + fechaB;
    }

    return result;
}

QString Recetas::searchRecetaPaciente(QString codigoPaciente)
{
    //QFile Recetas("/Users/Kenny/Documents/GitHub/App_Medica_Progra3/App_Medica/Recetas.itn");
    QFile Recetas("Recetas.itn");
    if (!Recetas.open(QIODevice::ReadOnly)) {
        return "No se puede abrir el archivo de recetas.";
    }

    QDataStream in(&Recetas);
    in.setVersion(QDataStream::Qt_5_0);

    QString result;
    bool found = false;

    while (!in.atEnd()) {
        qint64 code;
        QStringList medicamento;
        QString dosis;
        QString paciente;

        in >> code >> medicamento >> dosis >> paciente;

        if (paciente == codigoPaciente) {
            found = true;
            result += "Código: " + QString::number(code) + "\n";
            result += "Medicamento: " + medicamento.join(", ") + "\n";
            result += "Dosis: " + dosis + "\n";
        }
    }

    if (!found) {

        result = "No se encontraron recetas para el código de paciente " + codigoPaciente;
    }

    return result;
}

