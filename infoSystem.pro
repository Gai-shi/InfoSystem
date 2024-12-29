QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    allquery.cpp \
    company.cpp \
    delete.cpp \
    main.cpp \
    infosys.cpp \
    manager.cpp \
    modify.cpp \
    pushin.cpp \
    query.cpp \
    salesman.cpp \
    technician.cpp

HEADERS += \
    Config.h \
    allquery.h \
    company.h \
    delete.h \
    infosys.h \
    manager.h \
    modify.h \
    pushin.h \
    query.h \
    salesman.h \
    technician.h

FORMS += \
    allquery.ui \
    delete.ui \
    infosys.ui \
    modify.ui \
    pushin.ui \
    query.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
