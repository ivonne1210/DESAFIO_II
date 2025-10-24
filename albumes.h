#ifndef ALBUMES_H
#define ALBUMES_H
#include <string>

using namespace std;

class albumes {
private:
    string selloDisquero;
    string fechadelanzamiento;
    int duraciontotal;
    float puntuacion;
    string genero[4];
public:
    int idAlbum;
    string nombre;
    string portadaRuta;

    albumes();
    albumes(int _id, string _nom, string _sello, string _fecha, string _genero, int _dura, float _pun, string _portada);

};

#endif // ALBUMES_H
