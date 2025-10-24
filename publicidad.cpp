#include "publicidad.h"

using namespace std;

Publicidad::Publicidad() : mensaje(""), categoria(), prioridad() {}

Publicidad::Publicidad(const string& msg, char cat) {
    if (msg.size() > 500) {
        mensaje = msg.substr(0, 500);
    } else {
        mensaje = msg;
    }

    categoria = cat;
    if (cat == 'A') prioridad = 3;
    else if (cat == 'B') prioridad = 2;
    else prioridad = 1;
}

string Publicidad::getMensaje() const { return mensaje; }
int Publicidad::getPrioridad() const { return prioridad; }
char Publicidad::getCategoria() const { return categoria; }
