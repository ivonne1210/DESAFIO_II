#ifndef USUARIOS_H
#define USUARIOS_H
#include <string>
#include "ListaFavoritos.h"
using namespace std;

class Usuario
{
private:
    string city;
    string country;
    string regist;
    int member_type;
    string nick;
public:
    // Constructor
    Usuario();
    Usuario(string _nick,int _member_type, string _city, string _country, string _regist);
    bool seguirLista(Usuario& otroUsuario, ListaFavoritos * ListaFav);
    void dejarDeSeguir(const string& nombreSeguido);

    // Metodo
    bool esPremium();
    void mostrarUsuario() const;
    string getNombre(){return nick;};
};

#endif // USUARIOS_H
