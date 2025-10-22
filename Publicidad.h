#ifndef PUBLICIDAD_H
#define PUBLICIDAD_H
#include <iostream>
#include <string>
using namespace std;

class Publicidad {
private:
    string mensaje;
    char categoria; // 'C', 'B', 'A' (A = AAA)
    int prioridad;

public:
    Publicidad() {
        mensaje = "";
        categoria = 'C';
        prioridad = 1;
    }

    Publicidad(string msg, char cat) {
        mensaje = msg;
        categoria = cat;
        if (cat == 'A') prioridad = 3;
        else if (cat == 'B') prioridad = 2;
        else prioridad = 1;
    }

    string getMensaje() const { return mensaje; }
    int getPrioridad() const { return prioridad; }
};



#endif // PUBLICIDAD_H
