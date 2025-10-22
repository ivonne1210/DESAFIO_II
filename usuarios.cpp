#include <string>
#include "iostream"
#include "usuarios.h"
using namespace std;

Usuario::Usuario(string _nick,int _member_type, string _city, string _country, string _regist){
    this->nick = _nick;
    this->member_type = _member_type;
    this->city = _city;
    this->country = _country;
    this->regist = _regist;
}

Usuario::Usuario() {
    this->nick = "";
    this->member_type = 0;
    this->city = "";
    this->country = "";
    this->regist = "";
}
bool Usuario::esPremium(int _member_type){
    return _member_type == 1;
}

void Usuario::mostrarUsuario() const {
    cout << "Nick: " << nick
         << "\nTipo: " << (member_type == 1 ? "Premium" : "Estandar")
         << "\nCiudad: " << city
         << "\nPais: " << country
         << "\nRegistro: " << regist << "\n\n";
}
