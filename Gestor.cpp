#include "Gestor.h"
#include <sstream>
#include <fstream>
#include "publicidad.h"

Gestor::Gestor()
    : anuncios(nullptr), numAnuncios(0), ultimoIndice(-1) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

Gestor::~Gestor() {
    delete[] anuncios;
}

void Gestor::agregarAnuncio(const Publicidad& p) {
    Publicidad* temp = new Publicidad[numAnuncios + 1];
    for (int i = 0; i < numAnuncios; ++i)
        temp[i] = anuncios[i];

    temp[numAnuncios] = p;

    delete[] anuncios;
    anuncios = temp;
    ++numAnuncios;
}

bool Gestor::vacio() const {
    return numAnuncios == 0;
}

Publicidad Gestor::obtenerAnuncio() {
    if (vacio()) return Publicidad("Sin anuncios disponibles", 'C');

    int suma = 0;
    for (int i = 0; i < numAnuncios; ++i)
        suma += anuncios[i].getPrioridad();

    int seleccionado = -1;
    do {
        int r = std::rand() % suma;
        int acumulado = 0;

        for (int i = 0; i < numAnuncios; ++i) {
            acumulado += anuncios[i].getPrioridad();
            if (r < acumulado) {
                seleccionado = i;
                break;
            }
        }
    } while (seleccionado == ultimoIndice);

    ultimoIndice = seleccionado;
    return anuncios[seleccionado];
}

void Gestor::cargarDesdeArchivo(const string& rutaArchivo) {
    ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;

        stringstream ss(linea);
        string mensaje;
        char categoria;
        getline(ss, mensaje, '|');
        ss >> categoria;

        Publicidad p(mensaje, categoria);
        agregarAnuncio(p);
    }

    archivo.close();
}
