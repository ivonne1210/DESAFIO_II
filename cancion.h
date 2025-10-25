#ifndef CANCION_H
#define CANCION_H
#include <string>
#include "creditos.h"
using namespace std;

class Cancion {
private:
    unsigned int reproducciones;

public:
    unsigned int id;
    string name;
    int duration;
    string ruta128;
    string ruta320;
    Creditos creditos;

    Cancion();
    Cancion(unsigned int _id, string _nombre, int _duracion, string _ruta128, string _ruta320);

    void setCancion();
    void mostrarCancion() const;
};

#endif
