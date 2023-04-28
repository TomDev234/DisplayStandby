QT += core gui
QT += widgets
QT += webenginewidgets

CONFIG += c++11
CONFIG += precompile_header
PRECOMPILED_HEADER = pch.h

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    displaycontroller.cpp \
    helpbook.cpp \
    jsonserializer.cpp \
    main.cpp \
    mainwindow.cpp \
    messagebox.cpp \
    monitormodel.cpp \
    userdefaults.cpp

HEADERS += \
    displaycontroller.h \
    helpbook.h \
    jsonserializable.h \
    jsonserializer.h \
    mainwindow.h \
    messagebox.h \
    monitormodel.h \
    userdefaults.h

FORMS += \
    helpbook.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    hype.qrc \
    images.qrc
