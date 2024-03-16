QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admincodes.cpp \
    adminexpedientes.cpp \
    adminroles.cpp \
    adminsalas.cpp \
    citas.cpp \
    classcreateuser.cpp \
    main.cpp \
    mainwindow.cpp \
    recetas.cpp \
    reservas.cpp

HEADERS += \
    admincodes.h \
    adminexpedientes.h \
    adminroles.h \
    adminsalas.h \
    citas.h \
    classcreateuser.h \
    mainwindow.h \
    recetas.h \
    reservas.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
