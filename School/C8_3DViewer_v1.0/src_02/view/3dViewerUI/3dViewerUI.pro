QT       += core gui opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(3rdparty/qtgifimage/src/gifimage/qtgifimage.pri)

LIBS += -lopengl32

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../modules/affine_transformations.c \
    ../../modules/model_loading.c \
    glwidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../../modules/affine_transformations.h \
    ../../modules/model_loading.h \
    ../../modules/s21_3dviewer.h \
    glwidget.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

ICON = assets/AppIcon.icns

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
