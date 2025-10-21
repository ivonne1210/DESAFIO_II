#include "interfaz.h"
#include <iostream>
using namespace std;

Interfaz::Interfaz() {
    // Constructor vacío
}

void Interfaz::mostrarEstandar(Artista artista, albumes album, Cancion cancion) {
    system("cls");
    cout << "--------------------------------------------\n";
    cout << "               REPRODUCTOR UdeATunes\n";
    cout << "--------------------------------------------\n\n";

    // Bloque informativo principal
    cout << "          Cantante: " << artista.name << endl;
    cout << "          Album: " << album.nombre << endl;
    cout << "Ruta a la portada del album: " << album.portadaRuta << endl << endl;

    cout << "          Cancion reproducida: " << cancion.name << endl;
    cout << "Ruta al archivo de audio: " << cancion.ruta128 << endl;
    cout << "          Duracion: " << cancion.duration << " segundos" << endl << endl;

    cout << "--------------------------------------------\n";
    cout << "Opciones de reproduccion:\n";
    cout << "1. Reproducir\n";
    cout << "2. Detener\n";
    cout << "3. Salir\n";
    cout << "--------------------------------------------\n";
}
