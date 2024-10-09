QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Antenna2DView.cpp \
    LinkDesignManager.cpp \
    linkItem/AmplifierLinkItem.cpp \
    linkItem/AttenuatorLinkItem.cpp \
    linkItem/MixerLinkItem.cpp \
    linkItem/PhaseShifterLinkItem.cpp \
    linkItem/SubArrayLinkItem.cpp \
    linkItem/WaveFilterLinkItem.cpp \
    linkItem/BaseLinkItem.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Antenna2DView.h \
    LinkDesignManager.h \
    graphics.h \
    linkItem/AmplifierLinkItem.h \
    linkItem/AttenuatorLinkItem.h \
    linkItem/MixerLinkItem.h \
    linkItem/PhaseShifterLinkItem.h \
    linkItem/SubArrayLinkItem.h \
    linkItem/WaveFilterLinkItem.h \
    linkItem/BaseLinkItem.h \
    linkdesign_common.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
