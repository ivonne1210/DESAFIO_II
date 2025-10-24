#include "GestorPublicidad.h"

GestorPublicidad::GestorPublicidad()
    : anuncios(nullptr), numAnuncios(0), ultimoIndice(-1) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

GestorPublicidad::~GestorPublicidad() {
    delete[] anuncios;
}

void GestorPublicidad::agregarAnuncio(const Publicidad& p) {
    Publicidad* temp = new Publicidad[numAnuncios + 1];
    for (int i = 0; i < numAnuncios; ++i)
        temp[i] = anuncios[i];

    temp[numAnuncios] = p;

    delete[] anuncios;
    anuncios = temp;
    ++numAnuncios;
}

bool GestorPublicidad::vacio() const {
    return numAnuncios == 0;
}

Publicidad GestorPublicidad::obtenerAnuncio() {
    if (vacio()) return Publicidad("Sin anuncios disponibles", 'C');

    int suma = 0;
    for (int i = 0; i < numAnuncios; ++i)
        suma += anuncios[i].getPrioridad();

    int seleccionado = -1;
    do {
        int r = std::rand() % suma;
        int acumulado = 0;

        for (int i = 0; i < numAnuncios; ++i) {
            acumulado += anuncios[i].getPrioridad();
            if (r < acumulado) {
                seleccionado = i;
                break;
            }
        }
    } while (seleccionado == ultimoIndice);

    ultimoIndice = seleccionado;
    return anuncios[seleccionado];
}
