#include "creditos.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Creditos::Creditos() {
    totalProductores = totalMusicos = totalCompositores = 0;
}

void Creditos::agregarProductor(string nom, string ape, string cod) {
    if (totalProductores < 5) {
        productores[totalProductores++] = {nom, ape, cod};
    }
}

void Creditos::agregarMusico(string nom, string ape, string cod) {
    if (totalMusicos < 5) {
        musicos[totalMusicos++] = {nom, ape, cod};
    }
}

void Creditos::agregarCompositor(string nom, string ape, string cod) {
    if (totalCompositores < 5) {
        compositores[totalCompositores++] = {nom, ape, cod};
    }
}

void Creditos::mostrarCreditos() const {
    cout << "\n Creditos de la cancion:\n";
    cout << " Productores:\n";
    for (int i = 0; i < totalProductores; i++)
        cout << "  - " << productores[i].nombre << " " << productores[i].apellido
             << " (" << productores[i].codigoAfiliacion << ")\n";

    cout << " Musicos:\n";
    for (int i = 0; i < totalMusicos; i++)
        cout << "  - " << musicos[i].nombre << " " << musicos[i].apellido
             << " (" << musicos[i].codigoAfiliacion << ")\n";

    cout << " Compositores:\n";
    for (int i = 0; i < totalCompositores; i++)
        cout << "  - " << compositores[i].nombre << " " << compositores[i].apellido
             << " (" << compositores[i].codigoAfiliacion << ")\n";
}

void Creditos::cargarDesdeString(const string& data) {
    stringstream ss(data);
    string bloque;

    // Separar por grupos usando '-'
    while (getline(ss, bloque, '-')) {
        if (bloque.empty()) continue;
        string tipo, contenido;
        size_t pos = bloque.find('=');
        if (pos == string::npos) continue;

        tipo = bloque.substr(0, pos);
        contenido = bloque.substr(pos + 1);
        stringstream sc(contenido);
        string persona;

        while (getline(sc, persona, ',')) {
            if (persona.empty()) continue;
            size_t pos2 = persona.find(':');
            if (pos2 == string::npos) continue;
            string nombreCompleto = persona.substr(0, pos2);
            string codigo = persona.substr(pos2 + 1);
            stringstream sp(nombreCompleto);
            string nombre, apellido;
            sp >> nombre >> apellido;

            if (tipo == "productores") agregarProductor(nombre, apellido, codigo);
            else if (tipo == "musicos") agregarMusico(nombre, apellido, codigo);
            else if (tipo == "compositores") agregarCompositor(nombre, apellido, codigo);
        }
    }
}
