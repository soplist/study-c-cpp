#-------------------------------------------------
#
# Project created by QtCreator 2012-06-20T15:10:19
#
#-------------------------------------------------

QT       += core gui  sql

TARGET = Bank
TEMPLATE = app


SOURCES += main.cpp\
        adminlogin.cpp \
    adminall.cpp \
    addaccount.cpp \
    admindao.cpp \
    account.cpp \
    accountdao.cpp \
    seachaccount.cpp \
    transfer.cpp \
    deposite.cpp \
    withdraw.cpp \
    changepasswd.cpp

HEADERS  += adminlogin.h \
    adminall.h \
    addaccount.h \
    admin.h \
    admindao.h \
    account.h \
    accountdao.h \
    seachaccount.h \
    transfer.h \
    deposite.h \
    withdraw.h \
    changepasswd.h

FORMS    += adminlogin.ui \
    adminall.ui \
    addaccount.ui \
    seachaccount.ui \
    transfer.ui \
    deposite.ui \
    withdraw.ui \
    changepasswd.ui

RESOURCES += \
    pics.qrc
