/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QWidget *page_2;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *page_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QLabel *label_8;
    QWidget *page_4;
    QLabel *label_9;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QWidget *page_5;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_3;
    QLabel *label_12;
    QLineEdit *lineEdit_7;
    QLabel *label_13;
    QLineEdit *lineEdit_8;
    QLabel *label_14;
    QLineEdit *lineEdit_9;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QWidget *page_6;
    QPushButton *pushButton_18;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *lineEdit_10;
    QPushButton *pushButton_19;
    QLabel *label_17;
    QLineEdit *lineEdit_11;
    QWidget *page_7;
    QLabel *label_18;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QWidget *page_8;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QCalendarWidget *calendarWidget;
    QCalendarWidget *calendarWidget_2;
    QPushButton *pushButton_24;
    QPushButton *pushButton_25;
    QWidget *page_9;
    QLabel *label_25;
    QLabel *label_26;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 0, 781, 571));
        page = new QWidget();
        page->setObjectName("page");
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(340, 0, 61, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Black")});
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(350, 60, 41, 21));
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(310, 110, 141, 21));
        lineEdit_2 = new QLineEdit(page);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(310, 220, 151, 21));
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(350, 180, 49, 16));
        pushButton = new QPushButton(page);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(350, 330, 80, 24));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_4 = new QLabel(page_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(360, 10, 91, 31));
        label_4->setFont(font);
        label_5 = new QLabel(page_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(370, 70, 49, 16));
        lineEdit_4 = new QLineEdit(page_2);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(340, 170, 131, 21));
        label_6 = new QLabel(page_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(380, 140, 49, 16));
        label_7 = new QLabel(page_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(380, 210, 49, 16));
        lineEdit_5 = new QLineEdit(page_2);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(340, 100, 131, 21));
        lineEdit_6 = new QLineEdit(page_2);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(340, 240, 131, 21));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(360, 290, 80, 24));
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(40, 500, 80, 24));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        pushButton_4 = new QPushButton(page_3);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(270, 100, 191, 41));
        pushButton_5 = new QPushButton(page_3);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(270, 150, 191, 41));
        pushButton_6 = new QPushButton(page_3);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(270, 200, 191, 41));
        pushButton_7 = new QPushButton(page_3);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(270, 250, 191, 41));
        pushButton_8 = new QPushButton(page_3);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(270, 300, 191, 41));
        pushButton_9 = new QPushButton(page_3);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(270, 350, 191, 41));
        pushButton_10 = new QPushButton(page_3);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(270, 400, 191, 41));
        pushButton_11 = new QPushButton(page_3);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(270, 450, 191, 41));
        pushButton_12 = new QPushButton(page_3);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(60, 500, 80, 24));
        label_8 = new QLabel(page_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(270, 20, 181, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Black")});
        font1.setPointSize(18);
        font1.setBold(true);
        label_8->setFont(font1);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        label_9 = new QLabel(page_4);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(240, 10, 291, 41));
        label_9->setFont(font);
        pushButton_13 = new QPushButton(page_4);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(290, 80, 191, 41));
        pushButton_14 = new QPushButton(page_4);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(290, 150, 191, 41));
        pushButton_15 = new QPushButton(page_4);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(290, 220, 191, 41));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        label_10 = new QLabel(page_5);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(290, 10, 211, 31));
        label_10->setFont(font);
        label_11 = new QLabel(page_5);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(40, 80, 49, 16));
        lineEdit_3 = new QLineEdit(page_5);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(110, 80, 161, 21));
        label_12 = new QLabel(page_5);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(40, 130, 49, 16));
        lineEdit_7 = new QLineEdit(page_5);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(110, 130, 161, 21));
        label_13 = new QLabel(page_5);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(40, 180, 49, 16));
        lineEdit_8 = new QLineEdit(page_5);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(110, 180, 161, 21));
        label_14 = new QLabel(page_5);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(40, 230, 49, 16));
        lineEdit_9 = new QLineEdit(page_5);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(110, 230, 161, 21));
        pushButton_16 = new QPushButton(page_5);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(340, 290, 80, 24));
        pushButton_17 = new QPushButton(page_5);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setGeometry(QRect(40, 490, 80, 24));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        pushButton_18 = new QPushButton(page_6);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setGeometry(QRect(40, 510, 80, 24));
        label_15 = new QLabel(page_6);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(280, 10, 221, 31));
        label_15->setFont(font);
        label_16 = new QLabel(page_6);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(60, 100, 49, 16));
        lineEdit_10 = new QLineEdit(page_6);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(150, 100, 161, 21));
        pushButton_19 = new QPushButton(page_6);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(350, 100, 80, 24));
        label_17 = new QLabel(page_6);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(60, 170, 49, 16));
        lineEdit_11 = new QLineEdit(page_6);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(150, 170, 161, 21));
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        label_18 = new QLabel(page_7);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(270, 20, 251, 31));
        label_18->setFont(font);
        pushButton_20 = new QPushButton(page_7);
        pushButton_20->setObjectName("pushButton_20");
        pushButton_20->setGeometry(QRect(290, 80, 191, 41));
        pushButton_21 = new QPushButton(page_7);
        pushButton_21->setObjectName("pushButton_21");
        pushButton_21->setGeometry(QRect(290, 140, 191, 41));
        pushButton_22 = new QPushButton(page_7);
        pushButton_22->setObjectName("pushButton_22");
        pushButton_22->setGeometry(QRect(290, 200, 191, 41));
        pushButton_23 = new QPushButton(page_7);
        pushButton_23->setObjectName("pushButton_23");
        pushButton_23->setGeometry(QRect(290, 270, 191, 41));
        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        label_19 = new QLabel(page_8);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(320, 10, 181, 31));
        label_19->setFont(font);
        label_20 = new QLabel(page_8);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(60, 60, 49, 16));
        label_21 = new QLabel(page_8);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(300, 60, 71, 16));
        label_22 = new QLabel(page_8);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(550, 60, 71, 16));
        label_23 = new QLabel(page_8);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(60, 110, 91, 16));
        label_24 = new QLabel(page_8);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(550, 110, 121, 16));
        calendarWidget = new QCalendarWidget(page_8);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(40, 140, 291, 211));
        calendarWidget_2 = new QCalendarWidget(page_8);
        calendarWidget_2->setObjectName("calendarWidget_2");
        calendarWidget_2->setGeometry(QRect(460, 140, 301, 201));
        pushButton_24 = new QPushButton(page_8);
        pushButton_24->setObjectName("pushButton_24");
        pushButton_24->setGeometry(QRect(350, 390, 80, 24));
        pushButton_25 = new QPushButton(page_8);
        pushButton_25->setObjectName("pushButton_25");
        pushButton_25->setGeometry(QRect(40, 510, 80, 24));
        stackedWidget->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        label_25 = new QLabel(page_9);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(340, 20, 151, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI Black")});
        font2.setPointSize(16);
        label_25->setFont(font2);
        label_26 = new QLabel(page_9);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(30, 70, 49, 16));
        stackedWidget->addWidget(page_9);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(8);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "User", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Rol", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Registro", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Nombre:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Rol:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "User:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Crear", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Administraci\303\263n del Sistema", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Administraci\303\263n de Salas", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Expedientes", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Recetas", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Reservaciones", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Agente de Consultas", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Opciones de Usuario", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Reportes", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Men\303\272 Principal", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Administraci\303\263n del Sistema", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Crear nuevo usuario", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Dar baja a un usuario", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Regresar", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Crear Nuevo Usuario", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Nombre:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Cuenta:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Rol:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "Crear", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "Regresar", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "Regresar", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Dar de baja a Usuario", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Usuario:", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "Buscar", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Administraci\303\263n de Salas ", nullptr));
        pushButton_20->setText(QCoreApplication::translate("MainWindow", "Crear nueva sala", nullptr));
        pushButton_21->setText(QCoreApplication::translate("MainWindow", "Modificar sala", nullptr));
        pushButton_22->setText(QCoreApplication::translate("MainWindow", "Eliminar sala", nullptr));
        pushButton_23->setText(QCoreApplication::translate("MainWindow", "Regresar ", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Crear Nueva Sala", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "C\303\263digo:", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Descripci\303\263n:", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Fecha de Inicio:", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Fin de Disponibilidad:", nullptr));
        pushButton_24->setText(QCoreApplication::translate("MainWindow", "Crear", nullptr));
        pushButton_25->setText(QCoreApplication::translate("MainWindow", "Regresar", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Modificar Sala", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Codigo:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
