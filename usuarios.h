#ifndef USUARIOS_H
#define USUARIOS_H
#include <string>

using namespace std;

class Usuario
{
private:
    string city;
    string country;
    string regist;
    int member_type;
public:
    string nick;

    // Constructor
    Usuario();
    Usuario(string _nick,int _member_type, string _city, string _country, string _regist);

    // Metodo
    bool esPremium();
    void mostrarUsuario() const;
};

#endif // USUARIOS_H
