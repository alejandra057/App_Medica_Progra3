#include "recetas.h"
#include "adminexpedientes.h"
#include <QDateTime>
#include <QMessageBox>

bool Recetas::crearNuevaReceta(long code, QString medicamento, QString dosis)
{
    QFile Recetas("Recetas.itn");
    if (!Recetas.open(QIODevice::Append)) {
        exit(0);
        return false;
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
    QDataStream in(&Recetas);
    in.setVersion(QDataStream::Qt_5_0);

    QString result;
    bool found = false;

    while (!in.atEnd()) {
        qint64 code;
        QStringList medicamento;
        QString dosis;
        QDate fecha;

        in >> code >> medicamento >> dosis >> fecha;

        if (fecha.toString("yyyy-MM-dd") == fechaB) {
            found = true;
            result += "Código: " + QString::number(code) + "\n";
            result += "Medicamento: " + medicamento.join(", ") + "\n";
            result += "Dosis: " + dosis + "\n";
            result += "Fecha: " + fecha.toString("yyyy-MM-dd") + "\n\n";
        }
    }

    if (!found) {
        result = "No se encontraron recetas para la fecha " + fechaB;
    }

    return result;
}

QString Recetas::searchRecetaPaciente(QString codigoPaciente)
{
    QFile file("Recetas.itn");
    QDataStream in(&file);
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

