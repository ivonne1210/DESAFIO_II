#ifndef METRICAS_H
#define METRICAS_H

#include <iostream>
using namespace std;

class Metricas {
private:
    size_t iteraciones;
    size_t memoria;

public:
    // Constructor
    Metricas() : iteraciones(0), memoria(0) {}

    // Métodos básicos
    void reset() {
        iteraciones = 0;
        memoria = 0;
    }

    void sumarIteracion() {
        iteraciones++;
    }

    void sumarMemoria(size_t bytes) {
        memoria += bytes;
    }

    size_t getIteraciones() const { return iteraciones; }
    size_t getMemoria() const { return memoria; }

    void mostrar() const {
        cout << "\n===== Métricas de eficiencia =====" << endl;
        cout << "Iteraciones realizadas: " << iteraciones << endl;
        cout << "Memoria estimada usada: " << memoria << " bytes" << endl;
        cout << "==================================\n";
    }
    Metricas& operator+=(const Metricas& otra) {
        this->iteraciones += otra.iteraciones;
        this->memoria += otra.memoria;
        return *this;
    }
};

#endif
