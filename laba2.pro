QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    delaywindow.cpp \
    dialog.cpp \
    linkedlist.cpp \
    main.cpp \
    mainwindow.cpp \
    mymodel.cpp \
    node.cpp \
    qavl.cpp \
    qbase.cpp \
    qbst.cpp \
    qtnode.cpp \
    vector.cpp \
    vectornode.cpp

HEADERS += \
    delaywindow.h \
    dialog.h \
    linkedlist.h \
    mainwindow.h \
    mymodel.h \
    node.h \
    qavl.h \
    qbase.h \
    qbst.h \
    qtnode.h \
    vector.h \
    vectornode.h

FORMS += \
    delaywindow.ui \
    dialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES +=
