#include "cancion.h"
#include <iostream>
using namespace std;

Cancion::Cancion() {
    id = 0;
    name = "";
    duration = 0;
    ruta128 = "";
    ruta320 = "";
    reproducciones = 0;
}

Cancion::Cancion(size_t _id, string _nombre, int _duracion, string _ruta128, string _ruta320) {
    id = _id;
    name = _nombre;
    duration = _duracion;
    ruta128 = _ruta128;
    ruta320 = _ruta320;
    reproducciones = 0;
}

void Cancion::setCancion() {
    cout << "Ingrese nombre de la canción: ";
    getline(cin, name);

    cout << "Duración (s): ";
    cin >> duration;
    cin.ignore();

    cout << "Ruta 128 kbps: ";
    getline(cin, ruta128);

    cout << "Ruta 320 kbps: ";
    getline(cin, ruta320);
}

void Cancion::mostrarCancion() const {
    cout << name << " [" << duration << "s]"
         << " | ID: " << id
         << " | Reproducciones: " << reproducciones << endl;
}

void Cancion::reproducirCancion(bool altaCalidad) {
    reproducir(altaCalidad ? 320 : 128);
    reproducciones++;
}

void Cancion::reproducir(int calidad) {
    cout << "▶️ Reproduciendo '" << name << "' a " << calidad << " kbps..." << endl;
}
