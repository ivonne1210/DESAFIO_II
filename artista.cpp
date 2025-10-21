#include "artista.h"

#include <string>

using namespace std;

Artista::Artista() {
    this->idArtist = 0;
    this->name = "";
    this->country = "";
    this->age = 0;
    this->followers=0;
    this->position=0;
}
Artista::Artista(string _name, int _id, int _age, string _country, size_t _followers, int _position){
    this->name = _name;
    this->idArtist = _id;
    this->age = _age;
    this->country = _country;
    this->followers = _followers;
    this->position = _position;
}
