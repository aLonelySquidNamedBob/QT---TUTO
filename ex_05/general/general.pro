TEMPLATE = lib

CONFIG = staticlib
QMAKE_CXXFLAGS += -std=c++17

SOURCES = contenu.cc

HEADERS += \
    contenu.h \
    dessinable.h \
    support_a_dessin.h
