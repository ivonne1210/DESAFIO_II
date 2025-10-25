#include "interfaz.h"
#include <iostream>
using namespace std;

Interfaz::Interfaz() {
    // Constructor vacío
}

void Interfaz::mostrar(Artista artista, albumes album, Cancion cancion, Publicidad anuncio) {
    system("cls");
    cout << "--------------------------------------------\n";
    cout << "               REPRODUCTOR UdeATunes\n";
    cout << "--------------------------------------------\n";
    cout << ""<<anuncio.getMensaje()<<"\n";
    cout << "                  "<<anuncio.getCategoria()<<"        \n\n";

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

void Interfaz::mostrar(Artista artista, albumes album, Cancion cancion) {
    system("cls");
    cout << "--------------------------------------------\n";
    cout << "               REPRODUCTOR UdeATunes\n";
    cout << "--------------------------------------------\n\n";

    // Bloque informativo principal
    cout << "          Cantante: " << artista.name << endl;
    cout << "          Album: " << album.nombre << endl;
    cout << "Ruta a la portada del album: " << album.portadaRuta << endl << endl;

    cout << "          Cancion reproducida: " << cancion.name << endl;
    cout << "Ruta al archivo de audio: " << cancion.ruta320 << endl;
    cout << "          Duracion: " << cancion.duration/60 << ":" << cancion.duration%60 << " segundos" << endl;

    cout << "--------------------------------------------\n";
    cout << "Opciones de reproduccion:\n";
    cout << "1. Reproducir          2. Detener\n";
    cout << "3. Siguiente           4. Anterior\n";
    cout << "5. Repetir             6. Salir\n";
    cout << "--------------------------------------------\n";
}

void Interfaz::editarListaFav(Artista artista, albumes album, Cancion cancion) {
    system("cls");
    cout << "--------------------------------------------\n";
    cout << "               REPRODUCTOR UdeATunes\n";
    cout << "--------------------------------------------\n\n";

    // Bloque informativo principal
    cout << "          Cantante: " << artista.name << endl;
    cout << "          Album: " << album.nombre << endl;
    cout << "Ruta a la portada del album: " << album.portadaRuta << endl << endl;

    cout << "          Cancion reproducida: " << cancion.name << endl;
    cout << "Ruta al archivo de audio: " << cancion.ruta320 << endl;
    cout << "          Duracion: " << cancion.duration/60 << ":" << cancion.duration%60 << " segundos" << endl;

    cout << "--------------------------------------------\n";
    cout << "Opciones de reproduccion:\n";
    cout << "1. Agregar          2. Quitar\n";
    cout << "--------------------------------------------\n";

}
