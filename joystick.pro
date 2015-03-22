TEMPLATE = app
INCLUDEPATH +=
DEFINES +=

HEADERS += usbHidLib.h

SOURCES += main.c \
					 usbHidLib.c
					
unix: {
	macx: {
		CONFIG -= app_bundle qt warn_on release incremental global_init_link_order lib_version_first plugin_no_soname link_prl
		LIBS += -Wl,-framework,IOKit,-framework,CoreFoundation
		INCLUDEPATH += libs/darwin/include
		HEADERS += libs/darwin/include/hidapi.h
		SOURCES += libs/darwin/hid.c
	} else: !macx: {
		LIBS = -ludev
		INCLUDEPATH += libs/linux/include
		HEADERS += libs/linux/include/hidapi.h
		SOURCES += libs/linux/hid.c
	}
}
