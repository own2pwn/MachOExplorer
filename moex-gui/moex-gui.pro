#-------------------------------------------------
#
# Project created by QtCreator 2017-04-05T23:30:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MOEX
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

PRECOMPILED_HEADER = stable.h

CONFIG   += precompile_header

LIBMOEX_HEADER = $$files(../libmoex/*.h,true)
LIBMOEX_SOURCE = $$files(../libmoex/*.cpp,true)
MOEX_GUI_HEADER = $$files(../moex-gui/*.h,true)
MOEX_GUI_SOURCE = $$files(../moex-gui/*.cpp,true)

SOURCES += $$LIBMOEX_SOURCE $$MOEX_GUI_SOURCE
HEADERS  += $$LIBMOEX_HEADER $$MOEX_GUI_HEADER
FORMS    +=

macx{
    _BOOSTPATH = /usr/local/Cellar/boost/1.64.0_1
    INCLUDEPATH += "$${_BOOSTPATH}/include/"
    LIBS += -L$${_BOOSTPATH}/lib
}

INCLUDEPATH += ./../

RESOURCES += \
    moex.qrc

