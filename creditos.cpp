#include "creditos.h"
#include <iostream>
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
