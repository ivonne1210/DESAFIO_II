#include <iostream>
#include <string>
using namespace std;
#include "cancion.h"

// Implementación de los constructores
Cancion::Cancion(){
    this->id = 0;
    this->name = "";
    this->duration = 0;
    this->ruta128 = "";
    this->ruta320 = "";
}

Cancion::Cancion(size_t _id, string _nombre, int _duracion, string _ruta128, string _ruta320) {
    id = _id;
    name = _nombre;
    duration = _duracion;
    ruta128 = _ruta128;
    ruta320 = _ruta320;
}

// Método privado de reproducción
void Cancion::reproducir(int calidad) {
    cout << "Reproduciendo \"" << name
         << "\" en calidad " << calidad << " kbps" << endl;
    if (calidad == 128)
        cout << "Ruta del archivo: " << ruta128 << endl;
    else
        cout << "Ruta del archivo: " << ruta320 << endl;
}

// Métodos públicos
void Cancion::setCancion() {
    cout << "=== Registrar nueva cancion ===" << endl;
    cout << "ID: ";
    cin >> id;
    cin.ignore();

    cout << "Nombre: ";
    getline(cin, name);

    cout << "Duracion (segundos): ";
    cin >> duration;
    cin.ignore();

    cout << "Ruta 128 kbps: ";
    getline(cin, ruta128);

    cout << "Ruta 320 kbps: ";
    getline(cin, ruta320);

    cout << "Cancion registrada correctamente" << endl;
}

void Cancion::mostrarCancion() const {
    cout << "\n=== Informacion de la Cancion ===" << endl;
    cout << "ID: " << id << endl;
    cout << "Nombre: " << name << endl;
    cout << "Duracion: " << duration << " segundos" << endl;
    cout << "Ruta 128 kbps: " << ruta128 << endl;
    cout << "Ruta 320 kbps: " << ruta320 << endl;
}
