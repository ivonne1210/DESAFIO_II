#ifndef PUBLICIDAD_H
#define PUBLICIDAD_H

#include <string>

using namespace std;

class Publicidad {
private:
    string mensaje;
    char categoria;
    int prioridad;

public:
    Publicidad();
    Publicidad(const string& msg, char cat);

    string getMensaje() const;
    char getCategoria() const;
    int getPrioridad() const;
};

#endif // PUBLICIDAD_H
