QT       += core gui
QT += openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
include(./QtGifImage/src/gifimage/qtgifimage.pri)

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cc \
    Model/model.cc \
    Model/point.cc \
    Model/points.cc \
    Model/strategy.cc \
    Model/surfaces.cc \
    Controller/controller.cc \
    View/dialog.cc \
    View/glview.cc \
    View/view.cc

HEADERS += \
    Model/error.h \
    Model/model.h \
    Model/point.h \
    Model/points.h \
    Model/strategy.h \
    Model/surfaces.h \
    Controller/controller.h \
    View/dialog.h \
    View/glview.h \
    View/view.h

FORMS += \
    View/view.ui \
    View/dialog.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
