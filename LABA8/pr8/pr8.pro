QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PR8
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    draw.cpp \
    graph.cpp \
    main.cpp \
    stategraph.cpp \
    window.cpp

HEADERS += \
    draw.h \
    graph.h \
    matrix.h \
    stategraph.h \
    window.h

# Default rules for deployment.
#    |qnx: target.path = /tmp/$${TARGET}/bin
#    |else: unix:!android: target.path = /opt/$${TARGET}/bin
#    |!isEmpty(target.path): INSTALLS += target
