#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "classcreateuser.h"
#include "adminexpedientes.h"
#include "adminroles.h"
#include "adminsalas.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{
    classcreateuser crearuser;
    //login
    QString cuentauser=ui->cuenta->text();
    QString passworduser=ui->password->text();
    //ui->ver->text()=crearuser.BuscarUser(cuentauser,passworduser);
    if (crearuser.BuscarUser(cuentauser,passworduser," "))
    {
        ui->stackedWidget->setCurrentIndex(2);
    }else
    {
        QMessageBox::information(this, "Error", QString("User o password incorrectos."));
    }

}


void MainWindow::on_pushButton_3_pressed()
{
     ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_4_pressed()
{
      ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_5_pressed()
{
     ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_6_pressed()
{
     ui->stackedWidget->setCurrentIndex(10);
}


void MainWindow::on_pushButton_7_pressed()
{
     ui->stackedWidget->setCurrentIndex(13);
}


void MainWindow::on_pushButton_8_pressed()
{
    ui->stackedWidget->setCurrentIndex(13);
}


void MainWindow::on_pushButton_9_pressed()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_pushButton_10_pressed()
{
    ui->stackedWidget->setCurrentIndex(25);
}


void MainWindow::on_pushButton_11_pressed()
{
     ui->stackedWidget->setCurrentIndex(27);
}


void MainWindow::on_pushButton_13_pressed()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_14_pressed()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_pushButton_15_pressed()
{
    ui->stackedWidget->setCurrentIndex(2);
}



void MainWindow::on_pushButton_20_pressed()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pushButton_21_pressed()
{
    ui->stackedWidget->setCurrentIndex(8);
}


void MainWindow::on_pushButton_22_pressed()
{
    ui->stackedWidget->setCurrentIndex(10);
}


void MainWindow::on_pushButton_23_pressed()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_31_pressed()
{
     ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_pushButton_32_pressed()
{
     ui->stackedWidget->setCurrentIndex(12);
}


void MainWindow::on_pushButton_33_pressed()
{
     ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_38_pressed()
{
     ui->stackedWidget->setCurrentIndex(14);
}


void MainWindow::on_pushButton_39_pressed()
{
     ui->stackedWidget->setCurrentIndex(15);
}


void MainWindow::on_pushButton_40_pressed()
{
     ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_45_pressed()
{
     ui->stackedWidget->setCurrentIndex(17);
}


void MainWindow::on_pushButton_46_pressed()
{
     ui->stackedWidget->setCurrentIndex(18);
}


void MainWindow::on_pushButton_47_pressed()
{
     ui->stackedWidget->setCurrentIndex(19);
}


void MainWindow::on_pushButton_48_pressed()
{
     ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_55_pressed()
{
     ui->stackedWidget->setCurrentIndex(21);
}


void MainWindow::on_pushButton_56_pressed()
{
     ui->stackedWidget->setCurrentIndex(22);
}


void MainWindow::on_pushButton_57_pressed()
{
     ui->stackedWidget->setCurrentIndex(23);
}


void MainWindow::on_pushButton_58_pressed()
{
     ui->stackedWidget->setCurrentIndex(24);
}


void MainWindow::on_pushButton_59_pressed()
{
 ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_68_pressed()
{
    ui->stackedWidget->setCurrentIndex(26);
}


void MainWindow::on_pushButton_69_pressed()
{
     ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_72_pressed()
{
     ui->stackedWidget->setCurrentIndex(28);
}


void MainWindow::on_pushButton_73_pressed()
{
     ui->stackedWidget->setCurrentIndex(29);
}


void MainWindow::on_pushButton_78_pressed()
{
     ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_17_pressed()
{
     ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_18_pressed()
{
       ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_25_pressed()
{
     ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_27_pressed()
{
      ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_30_pressed()
{
     ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_35_pressed()
{
     ui->stackedWidget->setCurrentIndex(10);
}


void MainWindow::on_pushButton_37_pressed()
{
    ui->stackedWidget->setCurrentIndex(10);
}


void MainWindow::on_pushButton_41_pressed()
{
    ui->stackedWidget->setCurrentIndex(13);
}


void MainWindow::on_pushButton_44_pressed()
{
    ui->stackedWidget->setCurrentIndex(13);
}


void MainWindow::on_pushButton_50_pressed()
{
    ui->stackedWidget->setCurrentIndex(16);
}


void MainWindow::on_pushButton_52_pressed()
{
    ui->stackedWidget->setCurrentIndex(16);
}


void MainWindow::on_pushButton_54_pressed()
{
    ui->stackedWidget->setCurrentIndex(16);
}


void MainWindow::on_pushButton_61_pressed()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_pushButton_63_pressed()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_pushButton_65_pressed()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_pushButton_67_pressed()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_pushButton_71_pressed()
{
    ui->stackedWidget->setCurrentIndex(25);
}


void MainWindow::on_pushButton_75_pressed()
{
    ui->stackedWidget->setCurrentIndex(27);
}


void MainWindow::on_pushButton_77_pressed()
{
    ui->stackedWidget->setCurrentIndex(27);
}


void MainWindow::on_pushButton_clicked(bool checked)
{

}


void MainWindow::on_pushButton_released()
{

}


void MainWindow::on_pushButton_16_pressed()
{
    classcreateuser crearuser;
    QString crearnombre = ui->NombreCrear->text();
    QString crearcuenta= ui->CrearCuenta->text();
    QString Rol= ui->crearRol->text();
    bool status= true;
    if( crearuser.BuscarUser(crearcuenta,"",crearnombre))
    {
        QMessageBox::information(this, "Error", QString("El usuario ya existe."));
    }
    else
    {
        if (crearuser.CreateUserFun(crearnombre,"admin",crearcuenta,Rol,status))
        {
            QMessageBox::information(this, "Listo", QString("El usuario fue creado con exito."));
        }
    }
}


void MainWindow::on_pushButton_19_pressed()
{
    classcreateuser crearuser;
    QString nombre= ui->NombreEdit->text();
    QString cuenta=ui->UsuarioEdit->text();
    if(crearuser.CambiarStatus(nombre,cuenta))
    {
        QMessageBox::information(this, "Listo", QString("El usuario "+cuenta+"se ha marcado como inactivo"));
    }else{
         QMessageBox::information(this, "Error", QString("El usuario no existe."));
    }

}


void MainWindow::on_pushButton_34_pressed()
{
    //expedientes
    AdminExpedientes expedientes;
    QString encabezado= ui->EncabezadoCrear->text();
    QString namePaciente= ui->NamePacienteCrear->text();
    QString identidad = ui->IdentidadCrear->text();
    QDate fechaNacimiento = ui->calendarFechaNacimiento->selectedDate();
    QString strFechaNacimiento = fechaNacimiento.toString("yyyy-MM-dd");
    QString Telefono = ui->Telefonocrear->text();
    QString Email = ui->EmailCrear->text();
    QString nameadicional= ui->contacadiocionalCrear->text();
    QString TelefonoAdional = ui->TelefonoadiocionalCrear->text();
    QString EmailAdional = ui->EmailadionalCrear->text();
    QString tiposangre = ui->TipodeSangreCrear->currentData().toString();
    QString Alergias = ui->AlergiasCrear->text();
    QString Enfermedades = ui->EnfermedadesCrear->text();

        if(encabezado!=" " && namePaciente!=" " && identidad!=" " && strFechaNacimiento!=" " && Telefono!=" " && Email!=" " && nameadicional!=" " && TelefonoAdional!=" " && EmailAdional!=" " && tiposangre!=" " && Alergias!=" "&& Enfermedades!=" ")
        {
            //expedientes.addToExpediente(encabezado,namePaciente,identidad,strFechaNacimiento,Telefono,Email,nameadicional,TelefonoAdional,EmailAdional,tiposangre,Alergias,Enfermedades);
            expedientes.createNewExpediente(encabezado,namePaciente,identidad,strFechaNacimiento,Telefono,Email,nameadicional,TelefonoAdional, EmailAdional,Alergias,tiposangre,Enfermedades);
             QMessageBox::information(this, "listo", QString("Se ha creado correctamente el expediente."));
        }
        else
        {
            QMessageBox::information(this, "Error", QString("No ha llenado todos los datos."));
        }

}


void MainWindow::on_pushButton_36_pressed()
{
//adjuntar datos
    AdminExpedientes expedientes;
    QString name = ui->NamePaciente->text();
    QString identidad =ui->IdentidadPaciente->text();
    QString sintomas = ui->Sintomaspresen->text();
    QString observaciones = ui->Observacionepaci->text();
    QString Recomendaciones = ui->Observacionepaci->text();
    QString adicional = ui->AdicionalComents->text();
    QString diagnostico= ui->labelDiagnostico->text();

    QDate fecha = ui->feachaDeCita->selectedDate();
    QString strFecha = fecha.toString("yyyy-MM-dd");

    QDate fechacita = ui->ProximaCita->selectedDate();
    QString strFechaSiguienteCita= fechacita.toString("yyyy-MM-dd");


    if (expedientes.addToExpediente(name,identidad,strFecha,sintomas,observaciones,diagnostico,Recomendaciones,strFechaSiguienteCita,adicional))
    {
         QMessageBox::information(this, "listo", QString("Se ha adicionado correctamente el expediente."));
    }
    else
    {
        QMessageBox::information(this, "Error", QString("No existe dicho expediente."));
    }


}


void MainWindow::on_pushButton_79_pressed()
{
     ui->stackedWidget->setCurrentIndex(30);
}


void MainWindow::on_pushButton_80_pressed()
{

    adminRoles roles;
    QString Role = ui->otroRole->text();
    if(roles.addRole(Role))
    {
    QMessageBox::information(this, "listo", QString("Se ha creado correctamente el rol."));
        ui->stackedWidget->setCurrentIndex(3);
    }
    else
    {
        QMessageBox::information(this, "Error", QString("No se ha creado el rol."));
    }
}


void MainWindow::on_pushButton_24_pressed()
{

    AdminSalas Salas;
    QString status="Disponible";
    QString descripcion = ui->DescripcionSala->text();
    QDate fechainicio = ui->FechaStart->selectedDate();
    QString strfechainicio= fechainicio.toString("yyyy-MM-dd");
    QDate fecha_end = ui->FechaEnd->selectedDate();
    QString strfechaend=fecha_end.toString("yyyy-MM-dd");

    if(Salas.createNewSala(descripcion,status,strfechainicio,strfechaend))
    {
         QMessageBox::information(this, "listo", QString("Se ha creado correctamente la sala."));
    }else
    {
         QMessageBox::information(this, "Error", QString("No ha creado correctamente la sala."));
    }

}


void MainWindow::on_pushButton_26_pressed()
{
   /* adminSalas salas;
    int code= ui->CodeModificar->text().toInt();
    string descripcion = ui->DescripcioModificar->text().toStdString();
    QDate fechainit= ui->fechaStarModi->selectedDate();
    QDate fechaFinal = ui->fechaFinalDisponibilidad->selectedDate();
    if (salas.modificarSala(code,descripcion,"true",fechainit,fechaFinal))
    {
        QMessageBox::information(this, "listo", QString("Se ha modificado correctamente la sala."));
    }else{
        QMessageBox::information(this, "listo", QString("No se ha encontrado la sala."));
    }
*/
}


void MainWindow::on_EliminarSala_pressed()
{
   /* adminSalas salas;
    int code= ui->codeDelete->text().toInt();
    if (salas.eliminarSala(code)){
       QMessageBox::information(this, "listo", QString("Se ha eliminado correctamente la sala."));
    }
    else
    {
        QMessageBox::information(this, "listo", QString("No se ha podido eliminar correctamente la sala."));
    }
*/
}


void MainWindow::on_pushButton_clicked()
{

}

