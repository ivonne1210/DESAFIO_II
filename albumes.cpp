#include <string>
#include <sstream>
#include "albumes.h"

using namespace std;
albumes::albumes(){
    this->idAlbum = 0;
    this->nombre="";
    this->selloDisquero="";
    this->fechadelanzamiento="";
    this->duraciontotal=0;
    this->puntuacion=0;
    this->portadaRuta="";
    int i = 0;
    while (i < 4) {
        genero[i++] = "";
    }
}
albumes::albumes(int _id, string _nom, string _sello, string _fecha, string _genero, int _dura, float _pun, string _portada){
    this->idAlbum = _id;
    this->nombre=_nom;
    this->selloDisquero=_sello;
    this->fechadelanzamiento=_fecha;
    this->duraciontotal=_dura;
    this->puntuacion=_pun;
    this->portadaRuta=_portada;

    stringstream ss(_genero);
    string item;
    int i = 0;

    while (getline(ss, item, ',') && i < 4) {
        // Quitar espacios en blanco al inicio o final (opcional)
        if (!item.empty() && item[0] == ' ')
            item.erase(0, item.find_first_not_of(' '));
        this ->genero[i++] = item;
    }
    while (i < 4) {
        genero[i++] = "";
    }
}

