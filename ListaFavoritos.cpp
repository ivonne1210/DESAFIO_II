#include "ListaFavoritos.h"
#include <iostream>
#include <fstream>


using namespace std;

ListaFavoritos::ListaFavoritos() {
    cantidad = 0;
}

void ListaFavoritos::agregar(size_t idCancion) {
    for (int i = 0; i < cantidad; ++i) {
        if (ids[i] == idCancion) {
            cout << "La cancion ya está en favoritos.\n";
            return;
        }
    }
    ids[cantidad++] = idCancion;
    cout << "Cancion agregada a favoritos.\n";
}

void ListaFavoritos::eliminar(size_t idCancion) {
    for (int i = 0; i < cantidad; ++i) {
        if (ids[i] == idCancion) {
            for (int j = i; j < cantidad - 1; ++j)
                ids[j] = ids[j + 1];
            cantidad--;
            cout << "Cancion eliminada de favoritos.\n";
            return;
        }
    }
    cout << "Cancion no encontrada en favoritos.\n";
}

void ListaFavoritos::cargarDesdeArchivo(const string& rutaArchivo) {
    ifstream file(rutaArchivo);
    if (!file) {
        cout << "No existe lista de favoritos, se creará una nueva.\n";
        return;
    }
    size_t id;
    while (file >> id) {
        ids[cantidad++] = id;
    }
}

void ListaFavoritos::guardarEnArchivo(const string& rutaArchivo) const {
    ofstream file(rutaArchivo);
    for (int i = 0; i < cantidad; ++i)
        file << ids[i] << '\n';
}

void ListaFavoritos::mostrar(){
    for (int i = 0; i<cantidad;i++){
        cout << ids[i]<<endl;
    }
}


