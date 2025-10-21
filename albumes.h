#ifndef ALBUMES_H
#define ALBUMES_H
#include <string>
#include "cancion.h"

using namespace std;

class albumes {
private:
    string selloDisquero;
    string fechadelanzamiento;
    int duraciontotal;
    float puntuacion;
    string genero[4];
    int totalCanciones;
public:
    int idAlbum;
    string nombre;
    string portadaRuta;
    Cancion canciones[20];

    albumes(int _id, string _nom, string _sello, string _fecha, string _genero, int _dura, float _pun, string _portada);

    void cargarCancionesDesdeArchivos(string ruta);
    void mostrarAlbum();

};

#endif // ALBUMES_H
