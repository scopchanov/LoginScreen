QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LoginScreen
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    LoginPanel.cpp \
    EntryField.cpp \
    LineEdit.cpp \
    Label.cpp \
    LoginScreen.cpp

HEADERS += \
    LoginPanel.h \
    EntryField.h \
    LineEdit.h \
    Label.h \
    LoginScreen.h

RESOURCES += \
    resources.qrc
