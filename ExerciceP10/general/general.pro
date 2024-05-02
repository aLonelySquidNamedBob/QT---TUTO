TEMPLATE = lib

CONFIG = staticlib
QMAKE_CXXFLAGS += -std=c++17

SOURCES = quitourne.cc

HEADERS += \
    contenu.h \
    dessinable.h \
    support_a_dessin.h
