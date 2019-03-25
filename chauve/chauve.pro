#-------------------------------------------------
#
# Project created by QtCreator 2019-03-16T20:31:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chauve
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

CONFIG += c++17

RESOURCES += \
    application.qrc

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    replay.cpp \
    replaymanager.cpp \
    replaywidget.cpp \
    settingsdialog.cpp \
    settingsmanager.cpp

HEADERS += \
    mainwindow.h \
    replay.h \
    replaymanager.h \
    replaywidget.h \
    settingsdialog.h \
    settingsmanager.h

FORMS += \
    replaywidget.ui \
    settingsdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    protobuf/demo.proto \
    protobuf/dota_commonmessages.proto \
    protobuf/dota_shared_enums.proto \
    protobuf/dota_usermessages.proto \
    protobuf/netmessages.proto \
    protobuf/network_connection.proto \
    protobuf/networkbasetypes.proto \
    protobuf/usermessages.proto
