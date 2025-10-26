#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H

#include "cancion.h"
#include "usuarios.h"
#include "artista.h"
#include "albumes.h"
#include "metricas.h"
#include "ListaFavoritos.h"
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
    bool buscarCancion(size_t idCancion, Artista &artista_out, albumes &album_out, Cancion &cancion_out, Metricas &m);

public:
    Reproductor();
    void reproducirAleatorioListaFav(Usuario& u, ListaFavoritos* ListaFav);
    void reproducirSecuencialListaFav(Usuario& u, ListaFavoritos* listaFav);
    void mostrarCancion(size_t id_busqueda);
    void reproducirAleatorio(Usuario& u);
};

#endif
