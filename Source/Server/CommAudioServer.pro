#-------------------------------------------------
#
# Project created by QtCreator 2016-04-11T20:42:17
#
#-------------------------------------------------

QT       += core gui multimedia
QT       += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CommAudioServer
TEMPLATE = app

LIBS += -lws2_32

SOURCES += main.cpp\
    socket/ServerUDP.cpp \
    socket/CircularBuffer.cpp \
    socket/UDPSendWorker.cpp \
    socket/TCPControlWorker.cpp \
    socket/ClientServiceWorker.cpp \
    MainWindow.cpp

HEADERS  += \
    socket/Server.h \
    socket/ServerUDP.h \
    socket/CircularBuffer.h \
    socket/UDPSendWorker.h \
    socket/TCPControlWorker.h \
    socket/ClientServiceWorker.h \
    MainWindow.h \
    Global.h

FORMS    += mainwindow.ui

DISTFILES +=

CONFIG += c++11

RESOURCES += \
    qdarkstyle/style.qrc
