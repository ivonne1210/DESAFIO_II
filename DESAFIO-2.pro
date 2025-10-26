TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Gestor.cpp \
        ListaFavoritos.cpp \
        albumes.cpp \
        artista.cpp \
        cancion.cpp \
        creditos.cpp \
        interfaz.cpp \
        main.cpp \
        publicidad.cpp \
        reproductor.cpp \
        usuarios.cpp

HEADERS += \
    Gestor.h \
    ListaFavoritos.h \
    albumes.h \
    artista.h \
    cancion.h \
    creditos.h \
    interfaz.h \
    metricas.h \
    publicidad.h \
    reproductor.h \
    usuarios.h
