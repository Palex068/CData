QT       += core gui opengl openglwidgets
include(QtGifImage/gifimage/qtgifimage.pri)
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    backend/moving/moving_object_t.c \
    backend/moving/rotation_object_t.c \
    backend/moving/zoom_object_t.c \
    backend/moving/centralize_object_t.c \
    backend/moving/normalization_object_t.c \
    backend/parsing/init_object_t.c \
    backend/parsing/parsing_edges.c \
    backend/parsing/parsing_object_t.c \
    backend/parsing/parsing_vertexes.c \
    backend/parsing/remove_object_t.c \
    glview.cpp \
    main.cpp \
    mainwindow.cpp \
    options.cpp

HEADERS += \
    ../backend/3d_viewer.h \
    backend/3d_viewer.h \
    glview.h \
    mainwindow.h \
    options.h

FORMS += \
    mainwindow.ui \
    options.ui

macx:ICON = $${PWD}/icon/3DviewerLogo.icns

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
