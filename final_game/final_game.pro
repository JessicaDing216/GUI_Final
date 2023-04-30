TEMPLATE = app

QT += quick \
    widgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#LIBS += -lwiringPi
#INCLUDEPATH += /home/kn/raspi/sysroot/usr/include/

INCLUDEPATH += /usr/include
LIBS +=-L/usr/lib -lwiringPi

SOURCES += \
        final_game.cpp \
        main.cpp\
        wirpi.cpp

RESOURCES += qml.qrc \
    images.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    final_game.h\
    wirpi.h

