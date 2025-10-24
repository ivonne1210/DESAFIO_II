#ifndef GESTOR_H
#define GESTOR_H
#include <cstdlib>
#include <ctime>
#include "publicidad.h"

class Gestor {
private:
    Publicidad* anuncios;
    int numAnuncios;
    int ultimoIndice;

public:
    Gestor();
    ~Gestor();

    void agregarAnuncio(const Publicidad& p);
    bool vacio() const;
    Publicidad obtenerAnuncio();
    void cargarDesdeArchivo(const string& rutaArchivo);
};

#endif // GESTORPUBLICIDAD_H
