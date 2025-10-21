#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "artista.h"
#include "albumes.h"
#include "cancion.h"

using namespace std;

class Interfaz{
private:
    //Publicidad publi;
    Artista artista;
    albumes album;
    Cancion cancion;

public:
    Interfaz();

    void mostrarEstandar(Artista artista,albumes album, Cancion cancion);
};

#endif // INTERFAZ_H
