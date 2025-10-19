#ifndef ALBUMES_H
#define ALBUMES_H
#include <string>

using namespace std;

class albumes {
public:
    int idAlbum;
    string nombre;
    string selloDisquero;
    string fechadelanzamiento;
    string genero;
    float duraciontotal;
    float puntuacion;
    string portadaRuta;
    //cancion* canciones;

    albumes(int, string, string, string, string, float, float, string);
    //void agregarcancion(cancion c);
    void mostrarAlbum();

};

#endif // ALBUMES_H
