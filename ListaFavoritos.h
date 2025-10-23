#ifndef LISTAFAVORITOS_H
#define LISTAFAVORITOS_H

#include <string>

using namespace std;

class ListaFavoritos {
private:
    int cantidad;
    size_t ids[10000];

public:
    ListaFavoritos();

    void agregar(size_t idCancion);
    void eliminar(size_t idCancion);
    void cargarDesdeArchivo(const string& rutaArchivo);
    void guardarEnArchivo(const string& rutaArchivo) const;
    void mostrar();

    int getCantidad() const { return cantidad; }
    size_t getID(int index) const {
        if (index < 0 || index >= cantidad) return 0;
        return ids[index];
    }
};

#endif
