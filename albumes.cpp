#include <iostream>
#include <string>
#include "albumes.h"

using namespace std;

albumes::albumes(int _id, string _nom, string _sello, string _fecha, string _genero, float _dura, float _pun)/*string _portada*/{
    idAlbum = _id;
    nombre=_nom;
    selloDisquero=_sello;
    fechadelanzamiento=_fecha;
    genero=_genero;
    duraciontotal=_dura;
    puntuacion=_pun;
    //portadaRuta=_portada;

    this->idAlbum = _id;
    this->nombre=_nom;
    this->selloDisquero=_sello;
    this->fechadelanzamiento=_fecha;
    this->genero=_genero;
    this->duraciontotal=_dura;
    this->puntuacion=_pun;
    //this->portadaRuta=_portada;

}
