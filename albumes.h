#ifndef ALBUMES_H
#define ALBUMES_H
#include <string>

using namespace std;

class albumes {

private:
    string selloDisquero;
    string fechadelanzamiento;
    float duraciontotal;
    float puntuacion;
    string genero;
public:
    int idAlbum;
    string nombre;

    string portadaRuta;
    //cancion* canciones;

    albumes(int, string, string, string, string, float, float); //string);
    //void agregarcancion(cancion c);
    void mostrarAlbum();

};

#endif // ALBUMES_H
