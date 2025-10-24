#include "Publicidad.h"
#include <iostream>

using namespace std;

Publicidad::Publicidad() : mensaje(""), categoria('C'), prioridad(1) {}

Publicidad::Publicidad(const string& msg, char cat)
    : mensaje(msg), categoria(cat) {
    if (cat == 'A') prioridad = 3;
    else if (cat == 'B') prioridad = 2;
    else prioridad = 1;
}

string Publicidad::getMensaje() const { return mensaje; }
int Publicidad::getPrioridad() const { return prioridad; }
