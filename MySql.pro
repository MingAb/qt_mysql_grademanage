#-------------------------------------------------
#
# Project created by QtCreator 2019-05-27T12:24:26
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MySql
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

CONFIG += c++11

SOURCES += \
        main.cpp \
    admin.cpp \
    change_student.cpp \
    delete_student.cpp \
    widget.cpp \
    student.cpp \
    stu_user.cpp \
    course.cpp \
    change_course.cpp \
    delete_course.cpp \
    grade.cpp \
    retake.cpp \
    change_grade.cpp \
    delete_grade.cpp \
    change_retake.cpp \
    delete_retake.cpp \
    change_stu_state.cpp \
    change_stu_password.cpp

HEADERS += \
    admin.h \
    change_student.h \
    delete_student.h \
    student.h \
    widget.h \
    stu_user.h \
    course.h \
    change_course.h \
    delete_course.h \
    grade.h \
    retake.h \
    change_grade.h \
    delete_grade.h \
    change_retake.h \
    delete_retake.h \
    change_stu_state.h \
    change_stu_password.h

FORMS += \
    admin.ui \
    change_student.ui \
    delete_student.ui \
    student.ui \
    widget.ui \
    stu_user.ui \
    course.ui \
    change_course.ui \
    delete_course.ui \
    grade.ui \
    retake.ui \
    change_grade.ui \
    delete_grade.ui \
    change_retake.ui \
    delete_retake.ui \
    change_stu_state.ui \
    change_stu_password.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
