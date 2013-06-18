TARGET = vintage

# --- input
HEADERS += greyscale.h \
           sepia.h \
           oldcolorphoto.h \
           crossprocessing.h \
           vignette.h \
           vintageplugin.h

SOURCES += greyscale.cpp \
           sepia.cpp \
           oldcolorphoto.cpp \
           crossprocessing.cpp \
           vignette.cpp \
           vintageplugin.cpp

equals(QT_MAJOR_VERSION, 5): OTHER_FILES += vintage.json

include(../plugin.pri)
