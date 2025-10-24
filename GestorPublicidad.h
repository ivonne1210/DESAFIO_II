#ifndef GESTORPUBLICIDAD_H
#define GESTORPUBLICIDAD_H
#include <cstdlib>
#include <ctime>
#include "Publicidad.h"

class GestorPublicidad {
private:
    Publicidad* anuncios;
    int numAnuncios;
    int ultimoIndice;

public:
    GestorPublicidad();
    ~GestorPublicidad();

    void agregarAnuncio(const Publicidad& p);
    bool vacio() const;
    Publicidad obtenerAnuncio();
};

#endif // GESTORPUBLICIDAD_H
