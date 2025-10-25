#ifndef ARTISTA_H
#define ARTISTA_H
#include <cstdint>
#include <string>

using namespace std;

class Artista{
private:
    uint8_t age;
    string country;
    size_t followers;
    unsigned int position;
public:
    string name;
    unsigned int idArtist;

    // Constructor
    Artista();
    Artista(string _name, unsigned int _id, uint8_t _age, string _country, size_t _followers, unsigned int _position);
};

#endif // ARTISTA_H
