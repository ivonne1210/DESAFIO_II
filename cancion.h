#ifndef CANCION_H
#define CANCION_H
#include <string>
#include "creditos.h"
using namespace std;

class Cancion {
private:
    void reproducir(int calidad);

public:
    size_t id;         // 9 dígitos: 5 artista + 2 álbum + 2 canción
    string name;
    int duration;      // en segundos
    string ruta128;
    string ruta320;
    int reproducciones;
    Creditos creditos; // créditos de la canción

    Cancion();
    Cancion(size_t _id, string _nombre, int _duracion, string _ruta128, string _ruta320);

    void setCancion();
    void mostrarCancion() const;
    void reproducirCancion(bool altaCalidad);
};

#endif
