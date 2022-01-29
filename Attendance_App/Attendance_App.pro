QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    admin_panel.cpp \
    main.cpp \
    mainwindow.cpp \
    student.cpp \
    student_login.cpp \
    studentpanel.cpp \
    teacher.cpp \
    teacherspanel.cpp

HEADERS += \
    admin.h \
    admin_panel.h \
    mainwindow.h \
    student.h \
    student_login.h \
    studentpanel.h \
    teacher.h \
    teacherspanel.h

FORMS += \
    admin_panel.ui \
    mainwindow.ui \
    student_login.ui \
    studentpanel.ui \
    teacherspanel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc
