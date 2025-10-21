#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H

#include "cancion.h"
#include "usuarios.h"
#include "artista.h"
#include "albumes.h"
#include <cstdlib>   // rand()
#include <ctime>     // time()

using namespace std;

class Reproductor {
private:
    Cancion* actual;   // canción en reproducción
    bool reproduciendo;
    int indiceActual;  // índice de la canción actual
    bool repetir;
    void mostrarEstandar();

public:
    Reproductor();

    void reproducirAleatorio(Cancion *canciones, int totalCanciones, Usuario u, Artista artista_actual, albumes album_actual);
    void reproducirSecuencial(Cancion* canciones, int totalCanciones, Usuario u, Artista artista_actual, albumes album_actual);
    void detener();
};

#endif
