#include "recetas.h"
#include "adminexpedientes.h"
#include <QDateTime>
#include <QMessageBox>

/*void newReceta() {
    QDateTime fechaActual = QDateTime::currentDateTime();
    QDate fecha = fechaActual.date();
    QFile ExpedientesAdmin("Expedientes.itn");
    if (!ExpedientesAdmin.isOpen()) {
        exit(0);
    }

    QStringList pacientes;
    QTextStream in(&ExpedientesAdmin);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(',');
        if (parts.size() >= 2) {
            QString paciente = parts[1].trimmed();
            pacientes.append(paciente);
        }
    }
    ExpedientesAdmin.close();
    if (pacientes.isEmpty()) {
        QMessageBox::warning(this, "Advertencia", "No se encontraron pacientes en el archivo de expedientes.");
        return;
    }
 void searchReceta() {
         recetasListWidget->clear();

        QString filtro = filtroLineEdit->text();
        int filtroIndex = filtroComboBox->currentIndex();
        ira en el gui
        QFile file("recetas.txt");
        if (file.isOpen()) {
            QTextStream in(&file);
            QString receta;
            while (!in.atEnd()) {
                QString line = in.readLine();
                if ((filtroIndex == 0 && line.startsWith("Paciente") && line.contains(filtro, Qt::CaseInsensitive)) || // Filtro por paciente
                    (filtroIndex == 1 && line.startsWith("Fecha") && line.contains(filtro))) { // Filtro por fecha
                    receta += line + "\n"; // Fecha o Paciente
                    receta += in.readLine() + "\n"; // Paciente o Medicamento
                    receta += in.readLine() + "\n"; // Medicamento o Dosis
                    receta += in.readLine() + "\n\n"; // Dosis o Siguiente Receta
                } else if (receta.size() > 0) {
                    recetasListWidget->addItem(receta);
                    receta.clear();
                }
            }
tambien ira en el gui
            if (receta.size() > 0) {
                recetasListWidget->addItem(receta);
            }
            file.close();
        }
    }
}
*/

