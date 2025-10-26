#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "artista.h"
#include "albumes.h"
#include "cancion.h"
#include "publicidad.h"

using namespace std;

class Interfaz{
private:
    //Publicidad publi;
    Artista artista;
    albumes album;
    Cancion cancion;

public:
    Interfaz();

    void mostrar(Artista artista,albumes album, Cancion cancion, Publicidad anuncio, bool detener);
    void mostrar(Artista artista,albumes album, Cancion cancion, bool detener);
    void editarListaFav(Artista artista,albumes album, Cancion cancion);
};

#endif // INTERFAZ_H
