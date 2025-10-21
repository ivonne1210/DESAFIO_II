#ifndef ARTISTA_H
#define ARTISTA_H

#include <string>

using namespace std;

class Artista{
private:
    int age;
    string country;
    size_t followers;
    int position;
public:
    string name;
    int idArtist;

    // Constructor
    Artista();
    Artista(string _name, int _id, int _age, string _country, size_t _followers, int _position);
};

#endif // ARTISTA_H
