#ifndef CANCION_H
#define CANCION_H
#include <string>
using namespace std;

class Cancion {
private:
    // Método interno para reproducir según calidad (128 o 320 kbps)
    void reproducir(int calidad);

public:
    // Atributos
    size_t id;
    string name;
    int duration;
    string ruta128;
    string ruta320;

    // Constructores
    Cancion(); // Constructor por defecto
    Cancion(size_t _id, string _nombre, int _duracion, string _ruta128, string _ruta320);

    // Métodos públicos
    void setCancion();           // Cargar datos desde consola
    void mostrarCancion() const; // Mostrar datos por consola
};

#endif
