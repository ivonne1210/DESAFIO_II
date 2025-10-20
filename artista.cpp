#include "artista.h"

#include <string>

using namespace std;

Artista::Artista(int _id, int _age, string _country, size_t _followers, int _position){
    this->idArtist = _id;
    this->age = _age;
    this->country = _country;
    this->followers = _followers;
    this->position = _position;
}
