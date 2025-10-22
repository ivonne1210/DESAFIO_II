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
public:
    string nick;
    int member_type;

    // Constructor
    Usuario();
    Usuario(string _nick,int _member_type, string _city, string _country, string _regist);

    // Metodo
    bool esPremium(int _member_type);
    void mostrarUsuario() const;
};

#endif // USUARIOS_H
