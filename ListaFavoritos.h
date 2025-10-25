#ifndef LISTAFAVORITOS_H
#define LISTAFAVORITOS_H

#include <string>

using namespace std;

class ListaFavoritos {
private:
    unsigned int cantidad;
    unsigned int capacidad;
    size_t* ids;

public:
    ListaFavoritos();
    ~ListaFavoritos();
    void agregar(size_t idCancion);
    void eliminar(size_t idCancion);
    void cargarDesdeArchivo(const string& rutaArchivo);
    void guardarEnArchivo(const string& rutaArchivo) const;
    void mostrar();

    int getCantidad() const { return cantidad; }
    size_t getID(unsigned int index) const {
        if (index < 0 || index >= cantidad) return 0;
        return ids[index];
    };
    bool existeID(size_t id);

    ListaFavoritos operator+(const ListaFavoritos& otra) const {
        ListaFavoritos nueva;
        for (unsigned int i = 0; i < cantidad; ++i)
            nueva.agregar(ids[i]);
        for (unsigned int j = 0; j < otra.cantidad; ++j) {
            if (!nueva.existeID(otra.ids[j])) {
                nueva.agregar(otra.ids[j]);
            }
        }
        return nueva;
    }

};

#endif
