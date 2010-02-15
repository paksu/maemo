TARGET      = qthello
HEADERS     += 
SOURCES     +=  qtmain.cpp
FORMS       += 
LEXSOURCES  += #LEXS#
YACCSOURCES += #YACCS#

INCLUDEPATH +=
LIBS        +=
DEFINES     +=

# All generated files goes same directory
OBJECTS_DIR = build
MOC_DIR     = build
UI_DIR      = build

DESTDIR     = build
TEMPLATE    = app
DEPENDPATH  +=
VPATH       += src uis
CONFIG      -= 
CONFIG      += debug
QT=core gui

INSTALLS    += target
target.path  = /usr/bin/

INSTALLS    += desktop
desktop.path  = /usr/share/applications/hildon
desktop.files  = data/qthello.desktop

INSTALLS    += service
service.path  = /usr/share/dbus-1/services
service.files  = data/qthello.service

INSTALLS    += icon64
icon64.path  = /usr/share/icons/hicolor/64x64/apps
icon64.files  = data/64x64/qthello.png

#
# Targets for debian source and binary package creation
#
debian-src.commands = dpkg-buildpackage -S -r -us -uc -d
debian-bin.commands = dpkg-buildpackage -b -r -uc -d
debian-all.depends = debian-src debian-bin

#
# Clean all but Makefile
#
compiler_clean.commands = -$(DEL_FILE) $(TARGET)

QMAKE_EXTRA_TARGETS += debian-all debian-src debian-bin compiler_clean
