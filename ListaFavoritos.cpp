#include "ListaFavoritos.h"
#include <iostream>
#include <fstream>


using namespace std;

ListaFavoritos::ListaFavoritos() {
    capacidad = 10;
    cantidad = 0;
    ids = new size_t[capacidad];
}

ListaFavoritos::~ListaFavoritos() {
    delete[] ids;
    ids = nullptr;
}

void ListaFavoritos::agregar(size_t idCancion) {
    if (cantidad >= capacidad) {
        capacidad *= 2;
        size_t* nuevo = new size_t[capacidad];
        for (int i = 0; i < cantidad; ++i)
            nuevo[i] = ids[i];
        delete[] ids;
        ids = nuevo;
    }
    ids[cantidad++] = idCancion;
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
    ifstream archivo(rutaArchivo);
    if (!archivo) return;

    cantidad = 0;
    size_t id;
    while (archivo >> id) {
        agregar(id);
    }
    archivo.close();
}

void ListaFavoritos::guardarEnArchivo(const string& rutaArchivo) const {
    ofstream archivo(rutaArchivo);
    if (!archivo) return;

    for (int i = 0; i < cantidad; ++i) {
        archivo << ids[i] << endl;
    }
    archivo.close();
}

void ListaFavoritos::mostrar(){
    for (int i = 0; i<cantidad;i++){
        cout << ids[i]<<endl;
    }
}

bool ListaFavoritos::existeID(size_t id) {
    for (int i = 0; i < cantidad; ++i) {
        if (ids[i] == id) return true;
    }
    return false;
}


