#include <iostream>
#include <string>
#include "albumes.h"

using namespace std;

albumes::albumes(int _id, string _nom, string _sello, string _fecha, string _genero, float _dura, float _pun, string _portada){
    this->idAlbum = _id;
    this->nombre=_nom;
    this->selloDisquero=_sello;
    this->fechadelanzamiento=_fecha;
    this->genero=_genero;
    this->duraciontotal=_dura;
    this->puntuacion=_pun;
    this->portadaRuta=_portada;
}
