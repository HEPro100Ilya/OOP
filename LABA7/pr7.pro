QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PR7
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        draw.cpp \
        graph.cpp \
        main.cpp \
        window.cpp

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

HEADERS += \
    draw.h \
    graph.h \
    matrix.h \
    window.h
