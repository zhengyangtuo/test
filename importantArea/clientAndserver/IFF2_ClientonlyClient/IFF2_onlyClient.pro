#-------------------------------------------------
#
# Project created by QtCreator 2020-05-06T13:50:50
#
#-------------------------------------------------

QT       += core gui network 3drender

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IFF2_onlyClient
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    QAMQP/qamqpauthenticator.cpp \
    QAMQP/qamqpchannel.cpp \
    QAMQP/qamqpchannelhash.cpp \
    QAMQP/qamqpclient.cpp \
    QAMQP/qamqpexchange.cpp \
    QAMQP/qamqpframe.cpp \
    QAMQP/qamqpmessage.cpp \
    QAMQP/qamqpqueue.cpp \
    QAMQP/qamqptable.cpp \
    netconnector.cpp \
#    flightexceptionmsg.cpp\
#    flightexception.cpp\
    qrabbitmq.cpp \
    importarea.cpp \
    criticalareaclient.cpp \
    criticalareamanagerclient.cpp \
    alarmdeviceclient.cpp \
    criticalarea.cpp \
    criticalareamanager.cpp \
    inspectresult.cpp \
    alarmdevice.cpp

HEADERS += \
        mainwindow.h \
    QAMQP/qamqpauthenticator.h \
    QAMQP/qamqpchannel.h \
    QAMQP/qamqpchannel_p.h \
    QAMQP/qamqpchannelhash_p.h \
    QAMQP/qamqpclient.h \
    QAMQP/qamqpclient_p.h \
    QAMQP/qamqpexchange.h \
    QAMQP/qamqpexchange_p.h \
    QAMQP/qamqpframe_p.h \
    QAMQP/qamqpglobal.h \
    QAMQP/qamqpmessage.h \
    QAMQP/qamqpmessage_p.h \
    QAMQP/qamqpqueue.h \
    QAMQP/qamqpqueue_p.h \
    QAMQP/qamqptable.h \
    netconnector.h \
#    flightexceptionmsg.h\
#    flightexception.h\
    qrabbitmq.h \
    importarea.h \
    criticalareaclient.h \
    criticalareamanagerclient.h \
    alarmdeviceclient.h \
    criticalarea.h \
    criticalareamanager.h \
    inspectresult.h \
    alarmdevice.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    lib/qamqpd.dll
