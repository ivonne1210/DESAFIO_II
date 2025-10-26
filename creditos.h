#ifndef CREDITOS_H
#define CREDITOS_H
#include <string>
#include <cstdint>
using namespace std;

struct Colaborador {
    string nombre;
    string apellido;
    string codigoAfiliacion;
};

class Creditos {
private:
    Colaborador productores[5];
    Colaborador musicos[5];
    Colaborador compositores[5];
    uint8_t totalProductores;
    uint8_t totalMusicos;
    uint8_t totalCompositores;

public:
    Creditos();

    void agregarProductor(string nom, string ape, string cod);
    void agregarMusico(string nom, string ape, string cod);
    void agregarCompositor(string nom, string ape, string cod);
    void cargarDesdeString(const string& data);

    void mostrarCreditos() const;
};

#endif
