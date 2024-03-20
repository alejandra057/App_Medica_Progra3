#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "classcreateuser.h"
#include "adminexpedientes.h"
#include "adminroles.h"
#include "adminsalas.h"
#include "admincodes.h"
#include "reservas.h"
#include <QMessageBox>
#include "recetas.h"
#include "citas.h"
QString NombreUserLogueado="";
QString role="admin";
QString code=0;
bool EsperaACrearExpediente=false;

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
        role=cuentauser;
        NombreUserLogueado=cuentauser;
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
    adminRoles roles;
    if(roles.permisoAdministrarUser(role))
    {
        ui->stackedWidget->setCurrentIndex(3);
    }
    else
    {
        QMessageBox::information(this, "Error", QString("No tiene permiso para ingresar."));
    }
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
    ui->stackedWidget->setCurrentIndex(16);
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
    adminRoles roles;

    if(roles.permisoVerReportes(role))
    {
         ui->stackedWidget->setCurrentIndex(27);
    }
    else
    {
        QMessageBox::information(this, "Error", QString("No tiene permiso para ingresar."));
    }
}


void MainWindow::on_pushButton_13_pressed()
{
    adminRoles roles;
    long cantidad = roles.cantRoles();
    for (long i = 0; i < cantidad; ++i) {
        QString Role1 = roles.showRoles();
        ui->RolUserCreate->addItem(Role1);
    }
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
    adminRoles roles;
    if(roles.permisoCrearSala(role)){
        ui->stackedWidget->setCurrentIndex(7);
    }
    else
    {
        QMessageBox::information(this, "Error", QString("No tiene permiso para ingresar."));
    }
}


void MainWindow::on_pushButton_21_pressed()
{
    adminRoles roles;
    if(roles.permisoEditarSala(role)){
    ui->stackedWidget->setCurrentIndex(8);
    }
    else
    {
        QMessageBox::information(this, "Error", QString("No tiene permiso para ingresar."));
    }
}


void MainWindow::on_pushButton_22_pressed()
{
    adminRoles roles;
    if(roles.permisoEditarSala(role)){
        ui->stackedWidget->setCurrentIndex(9);
    }
    else
    {
        QMessageBox::information(this, "Error", QString("No tiene permiso para ingresar."));
    }
}


void MainWindow::on_pushButton_23_pressed()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_31_pressed()
{
    adminRoles roles;
    AdminCodes codes;
    if(roles.permisoCrearExpedientes(role)){
        if(EsperaACrearExpediente==false)
        {
            EsperaACrearExpediente=true;
            long codigo = codes.NextcodigoExpedientes();
            code = QString::number(codigo);
            ui->CodigoNextExpedienteLabel->setText(code);
        }
        ui->stackedWidget->setCurrentIndex(11);
    }
    else
    {
        QMessageBox::information(this, "Error", QString("No tiene permiso para ingresar."));
    }
}


void MainWindow::on_pushButton_32_pressed()
{
    adminRoles roles;
    if(roles.permisoEditarExpediente(role)){
        ui->stackedWidget->setCurrentIndex(12);
    }
    else
    {
        QMessageBox::information(this, "Error", QString("No tiene permiso para ingresar."));
    }
}


void MainWindow::on_pushButton_33_pressed()
{
     ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_38_pressed()
{
    adminRoles roles;
    if(roles.permisoCrearRecetas(role)){
        ui->stackedWidget->setCurrentIndex(14);
    }
    else
    {
        QMessageBox::information(this, "Error", QString("No tiene permiso para ingresar."));
    }
}


void MainWindow::on_pushButton_39_pressed()
{
    adminRoles roles;
    if(roles.permisoEditarRecetas(role)){
     ui->stackedWidget->setCurrentIndex(15);
    }
    else
    {
        QMessageBox::information(this, "Error", QString("No tiene permiso para ingresar."));
    }
}


void MainWindow::on_pushButton_40_pressed()
{
     ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_45_pressed()
{
    AdminCodes codes;
    adminRoles roles;
    if(roles.permisoReservaciones(role)){
    long bytes = 0;
    long cant_codigos = 0 ;
    AdminSalas salas;

    while (cant_codigos <= codes.GetActualCodeSalas()) {
        long code = salas.getSala_Actal();
        if (code != -1) {
            ui->salas_cb->addItem(QString::number(code));
        }
        bytes += 32;
        cant_codigos++;
    }


    ui->stackedWidget->setCurrentIndex(17);
    }
    else
    {
        QMessageBox::information(this, "Error", QString("No tiene permiso para ingresar."));
    }
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
    adminRoles roles;
    if(roles.permisoCita(role))
    {
     ui->stackedWidget->setCurrentIndex(21);
    }
    else
    {
        QMessageBox::information(this, "Error", QString("No tiene permiso para ingresar."));
    }
}


void MainWindow::on_pushButton_56_pressed()
{
    adminRoles roles;
    if(roles.permisoCita(role))
    {
        AdminCodes codes;
        long bytes = 0;
        long cant_codigos = 0 ;
        Citas cita;

        while (cant_codigos <= codes.GetActualCodeCitas()) {
            long code = cita.getCita_Actal();
            if (code != -1) {
                ui->cb_MDCita->addItem(QString::number(code));
            }
            bytes += 32;
            cant_codigos++;
        }

        ui->stackedWidget->setCurrentIndex(22);
    }
    else
    {
        QMessageBox::information(this, "Error", QString("No tiene permiso para ingresar."));
    }
}


void MainWindow::on_pushButton_57_pressed()
{
    adminRoles roles;
    if(roles.permisoCita(role))
    {
        ui->stackedWidget->setCurrentIndex(23);
    }
    else
    {
        QMessageBox::information(this, "Error", QString("No tiene permiso para ingresar."));
    }
}


void MainWindow::on_pushButton_58_pressed()
{
    adminRoles roles;
    if(roles.permisoCita(role))
    {
        ui->stackedWidget->setCurrentIndex(24);
    }
    else
    {
        QMessageBox::information(this, "Error", QString("No tiene permiso para ingresar."));
    }
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







void MainWindow::on_pushButton_16_pressed()
{
    classcreateuser crearuser;
    QString crearnombre = ui->NombreCrear->text();
    QString crearcuenta= ui->CrearCuenta->text();
   // QString Rol= ui->crearRol->text();
    bool status= true;
    if( crearuser.BuscarUser(crearcuenta,"",crearnombre))
    {
        QMessageBox::information(this, "Error", QString("El usuario ya existe."));
    }
    else
    {
        if (crearuser.CreateUserFun(crearnombre,"admin",crearcuenta,"Rol",status))
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
    //QString encabezado= ui->EncabezadoCrear->text();



    QString namePaciente= ui->NamePacienteCrear->text();
    QString identidad = ui->IdentidadCrear->text();
    QDate fechaNacimiento = ui->calendarFechaNacimiento->selectedDate();
    QString strFechaNacimiento = fechaNacimiento.toString("dd/MM/yyyy");
    QString Telefono = ui->Telefonocrear->text();
    QString Email = ui->EmailCrear->text();
    QString nameadicional= ui->contacadiocionalCrear->text();
    QString TelefonoAdional = ui->TelefonoadiocionalCrear->text();
    QString EmailAdional = ui->EmailadionalCrear->text();
    QString tiposangre = ui->TipodeSangreCrear->currentData().toString();
    QString Alergias = ui->AlergiasCrear->text();
    QString Enfermedades = ui->EnfermedadesCrear->text();

        if(code!=" " && namePaciente!=" " && identidad!=" " && strFechaNacimiento!=" " && Telefono!=" " && Email!=" " && nameadicional!=" " && TelefonoAdional!=" " && EmailAdional!=" " && tiposangre!=" " && Alergias!=" "&& Enfermedades!=" ")
        {
            //expedientes.addToExpediente(encabezado,namePaciente,identidad,strFechaNacimiento,Telefono,Email,nameadicional,TelefonoAdional,EmailAdional,tiposangre,Alergias,Enfermedades);
            expedientes.createNewExpediente(code,namePaciente,identidad,strFechaNacimiento,Telefono,Email,nameadicional,TelefonoAdional, EmailAdional,Alergias,tiposangre,Enfermedades);
            EsperaACrearExpediente=false;
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
    QString strFecha = fecha.toString("dd/MM/yyyy");

    QDate fechacita = ui->ProximaCita->selectedDate();
    QString strFechaSiguienteCita= fechacita.toString("dd/MM/yyyy");


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

    bool PermisoUser = ui->crearUser->isChecked();
    bool PermisoExpedientes = ui->crearExpedientes->isChecked();
    bool PermisoSala = ui->crearSalas->isChecked();
    bool PermisoEditSala = ui->editSala->isChecked();
    bool PermisoDesahibiltar = ui->DesaSala->isChecked();
    bool PermisoEditExpe = ui->EditExpe->isChecked();
    bool Permisoconvencional = ui->convencional->isChecked();
    bool PermisocrearReceta = ui->crearReceta->isChecked();
    bool PermisoeditReceta = ui->editReceta->isChecked();
    bool PermisoAgeCita = ui->crearSalas->isChecked();
    bool PermisoVerRepo = ui->VerRepo->isChecked();
    bool PermisoVerReservas = ui->VerReservas->isChecked();
    bool PermisoverCitas = ui->verCitas->isChecked();
    if(roles.addRole(Role,PermisoUser,PermisoExpedientes,PermisoSala,PermisoEditSala,PermisoDesahibiltar,PermisoEditExpe,Permisoconvencional,PermisocrearReceta,PermisoeditReceta,PermisoAgeCita,PermisoVerRepo,PermisoVerReservas,PermisoverCitas))
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
    AdminCodes codes;
    long codigo=codes.NextcodigoSala();
    QString codetext = QString::number(codigo);
    ui->lbcodesala->setText(codetext);
    QString status="Disponible";
    ui->lb_status->setText(status);
    QString descripcion = ui->DescripcionSala->text();
    QDate fechainicio = ui->FechaStart->selectedDate();
    QString strfechainicio= fechainicio.toString("dd/MM/yyyy");
    QDate fecha_end = ui->FechaEnd->selectedDate();
    QString strfechaend=fecha_end.toString("dd/MM/yyyy");
    QString horainicio =ui->horainicio_crearSala->time().toString("HH:mm");
    QString horafinal =ui->horafinal_crearSala->time().toString("HH:mm");

    if(Salas.createNewSala(codetext,descripcion,status,strfechainicio,strfechaend,horainicio,horafinal))
    {
         QMessageBox::information(this, "listo", QString("Se ha creado correctamente la sala."));
    }else
    {
         QMessageBox::information(this, "Error", QString("No ha creado correctamente la sala."));
    }
}


void MainWindow::on_pushButton_26_pressed()
{
    AdminSalas Salas;
    QString code = ui->CodeModificar->text();
    QString descripcion = ui->DescripcioModificar->text();
    QDate fechainits= ui->fechaStarModi->selectedDate();
    QString fechainit= fechainits.toString("dd/MM/yyyy");
    QString status = ui->status_modi->text();
    QDate fechaFinals = ui->fechaFinalDisponibilidad->selectedDate();
    QString fechaFinal= fechaFinals.toString("dd/MM/yyyy");
    QString horainicio =ui->horainicio_crearSala->time().toString("HH:mm");
    QString horafinal =ui->horafinal_modi->time().toString("HH:mm");
    if (Salas.modificateSala(code,descripcion,status,fechainit,fechaFinal,horainicio,horafinal))
    {
        QMessageBox::information(this, "listo", QString("Se ha modificado correctamente la sala."));
    }else{
        QMessageBox::information(this, "listo", QString("No se han hecho reservaciones aun."));
    }

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


void MainWindow::on_btNewCita_pressed()
{
    QString name = ui->txtnombrecita->text();
    QString fecha=ui->dateCita->date().toString("dd/MM/yyyy");
    QString hora=ui->TimeCita->time().toString("HH:mm");
    Citas cita;
    AdminCodes codes;
    long codigo=codes.NextcodigoCitas();
    QString codetext = QString::number(codigo);
    if(cita.CrearCitas(codetext,name,fecha,hora)){
        QMessageBox::information(this, "listo", QString("Creada Exitosamente."));
    }else
    {
        QMessageBox::information(this, "Error", QString("Error."));
    }
}


void MainWindow::on_pushButton_12_pressed()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_bt_reservar_pressed()
{
    Reservas reservar;
    AdminCodes codes;
    long codigo=codes.NextcodigoReservas();
    QString codetext = QString::number(codigo);
    ui->lbcodereservas->setText(codetext);
    QString fecha = ui->date_reserva->date().toString("dd/MM/yyyy");
    QString horaInicio = ui->Hora_inicio->time().toString("HH:mm");
    QString horaFinal = ui->Hora_final->time().toString("HH:mm");
    QString nombre = ui->txt_name->text();
    QString nameDoctor=ui->txtnamedoctor->text();
    QString observaciones=ui->txtobservaciones->text();
    QString salaselect=ui->salas_cb->currentText();

    if(reservar.Nuevareservacion(codetext,salaselect,nombre,fecha,horaInicio,horaFinal,nameDoctor,observaciones))
    {
        QMessageBox::information(this, "listo", QString("Reservado Exitosamente."));
    }else
    {
        QMessageBox::information(this, "Error", QString("No se pudo reservar."));
    }
}


void MainWindow::on_btmodificarR_pressed()
{
    Reservas reservar;
    if(ui->txtnombreMR->text().isEmpty() && ui->nameDoctorMR->text().isEmpty() && ui->txtobeservacionesMR->toPlainText().isEmpty())
    {
     QMessageBox::information(this, "listo", QString("Campos vacios."));
    }else
    {
        QString code = ui->txtcodereserva->text();
        QString nombre=ui->txtnombreMR->text();
        QString fecha = ui->FechaMR->date().toString("dd/MM/yyyy");
        QString horaInicio = ui->HoraIMR->time().toString("HH:mm");
        QString horaFinal = ui->HoraFMR->time().toString("HH:mm");
        QString nameDoctor=ui->nameDoctorMR->text();
        QString observaciones=ui->txtobeservacionesMR->toPlainText();
        if(reservar.ModificarReservacion(code,nombre,fecha,horaInicio,horaFinal,nameDoctor,observaciones))
        {
          QMessageBox::information(this, "listo", QString("Modificado correctamente."));
        }else{
            QMessageBox::information(this, "listo", QString("Error."));
        }
    }
}


void MainWindow::on_bt_buscarMR_pressed()
{
    Reservas reservar;
    QString code = ui->txtcodereserva->text();
    Reservas::STReservaciones reservacion = reservar.Revisarcodigo(code); // Obtén la reservación
    if (!reservacion.code.isEmpty())
    {
        QMessageBox::information(this, "listo", QString("Reservacion encontrada."));
        ui->txtnombreMR->setText(reservacion.nombre);
        ui->nameDoctorMR->setText(reservacion.namedoctor);
        QDate fecha = QDate::fromString(reservacion.fecha, "dd/MM/yyyy");
        ui->FechaMR->setDate(fecha);
        QTime horainicio = QTime::fromString(reservacion.horainicio, "HH:mm");
        ui->HoraIMR->setTime(horainicio);
        QTime horafinal = QTime::fromString(reservacion.horafinal, "HH:mm");
        ui->HoraFMR->setTime(horafinal);
        ui->txtobeservacionesMR->setText(reservacion.observacion);
    }

    else
    {
        QMessageBox::information(this, "listo", QString("Codigo Inexistente."));
    }
}


void MainWindow::on_bt_EliminarR_pressed()
{
     Reservas reservar;
    QString code = ui->txtcodeER->text();
     if(reservar.EliminarReservacion(code)){
        QMessageBox::information(this, "listo", QString("Eliminado Correctamente."));
     }else{
        QMessageBox::information(this, "listo", QString("Codigo no encontrado."));
     }
}



void MainWindow::on_pushButton_70_pressed()
{
    classcreateuser crearuser;
    QString contraActual = ui->ActualPasswordUser->text();
    QString newPasword = ui->NewPasswordUser->text();
    if(crearuser.ChangePassword("name",role,newPasword,contraActual)){
         QMessageBox::information(this, "listo", QString("Se cambio correctamente la password."));
    }else{
         QMessageBox::information(this, "Error", QString("Ingreso datos incorrectamente."));
    }
}


void MainWindow::on_new_recipe_pressed()
{
    /*
    Recetas recetas;
    QDateTime fechaActual = QDateTime::currentDateTime();
    QString fecha= fechaActual();
    ui->lb_fecha_actual->setText(fecha);
    QString paciente =paciente_cb->currentText();
    QString medicamentos = medicamentos_cb->currentText();
    QString dosis = dosis_cb->currentText();
    recetas.new_recetas(fecha,paciente,medicamentos,dosis);
*/

}


void MainWindow::on_buscar_sala_pressed()
{
    AdminSalas Salas;
    AdminSalas::newSala sala;
    QString codigo = ui->CodeModificar->text();
    QString texto_salas ="Código: " + sala.Code + "\n"
                          + "Descripción: " + sala.Descripcion + "\n"
                          + "Status: " + sala.Status + "\n"
                          + "Fecha de inicio: " + sala.FechaInicio + "\n"
                          + "Fecha de fin de disponibilidad: " + sala.FechaFinDisponibilidad + "\n"
                          + "Hora de inicio: " + sala.HoraInicio + "\n"
                          + "Hora de fin: " + sala.HoraFinal + "\n";
    if (Salas.BuscarCodigo(codigo)){
         ui->texto_sala->setText(texto_salas);
        QMessageBox::information(this, "listo", QString("Sala encontrada."));

    }else{
        QMessageBox::information(this, "listo", QString("Sala no encontrada."));
    }
}


void MainWindow::on_pushButton_76_clicked()
{

    AdminExpedientes Reportcitas;
    QString fechain = ui->datein->date().toString("dd/MM/yyyy");
    QString fechaend = ui->dateend->date().toString("dd/MM/yyyy");
    QString Reportecitas = Reportcitas.getExpedientesInRange(fechain,fechaend);
    ui->txtreportcitas->setText(Reportecitas);

}


void MainWindow::on_showpacientes_clicked()
{
    AdminExpedientes expedientes;
    QString fechain = ui->dateinpaciente->date().toString("dd/MM/yyyy");
    QString fechaend = ui->dateendpaciente->date().toString("dd/MM/yyyy");
    QString ReporteExpediente = expedientes.getExpedientesInRange(fechain,fechaend);
    ui->txtreporteexpedientes->setText(ReporteExpediente);
}


void MainWindow::on_bt_ModCita_pressed()
{


    //ui->stackedWidget->setCurrentIndex(17);

}

