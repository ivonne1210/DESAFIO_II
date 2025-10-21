#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H

#include "cancion.h"
#include "usuarios.h"
#include <cstdlib>   // rand()
#include <ctime>     // time()

using namespace std;

class Reproductor {
private:
    Cancion* actual;   // canción en reproducción
    bool reproduciendo;
    int indiceActual;  // índice de la canción actual
    bool repetir;

public:
    Reproductor();

    void reproducirAleatorio(Cancion* canciones[], int totalCanciones, Usuario* u);
    void detener();
    void mostrarMenu(Cancion* canciones[], int totalCanciones, Usuario* u);
};

#endif
