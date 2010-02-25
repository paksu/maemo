# -------------------------------------------------
# Project created by QtCreator 2010-02-21T19:17:20
# -------------------------------------------------
TARGET = bogui
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    gameview.cpp \
    breakout.cpp \
    paddle.cpp \
    collidingitem.cpp \
    vector2d.cpp \
    tile.cpp \
    bonus.cpp \
    ball.cpp \
    buttonwidget.cpp \
    breakoutlevelgenerator.cpp \
    util.cpp \
    paddlebonus.cpp \
    ballbonus.cpp \
    scorebonus.cpp
HEADERS += mainwindow.h \
    gameview.h \
    breakout.h \
    paddle.h \
    collidingitem.h \
    vector2d.h \
    tile.h \
    bonus.h \
    ball.h \
    buttonwidget.h \
    breakoutlevelgenerator.h \
    util.h \
    paddlebonus.h \
    ballbonus.h \
    scorebonus.h
FORMS += mainwindow.ui
RESOURCES += images.qrc
unix { 
    # VARIABLES
    isEmpty(PREFIX):PREFIX = /opt
    BINDIR = $$PREFIX/bin
    DATADIR = $$PREFIX/share
    DEFINES += DATADIR=\\\"$$DATADIR\\\" \
        PKGDATADIR=\\\"$$PKGDATADIR\\\"
    
    # MAKE INSTALL
    INSTALLS += target \
        desktop \
        icon48 \
        icon64
    target.path = $$BINDIR
    desktop.path = $$DATADIR/applications/hildon
    desktop.files += $${TARGET}.desktop
    iconxpm.path = $$DATADIR/pixmap
    iconxpm.files += ../data/maemo/$${TARGET}.xpm
    icon26.path = $$DATADIR/icons/hicolor/26x26/apps
    icon26.files += ../data/26x26/$${TARGET}.png
    icon48.path = $$DATADIR/icons/hicolor/48x48/apps
    icon48.files += ../data/48x48/$${TARGET}.png
    icon64.path = $$DATADIR/icons/hicolor/64x64/apps
    icon64.files += ../data/64x64/$${TARGET}.png
}
