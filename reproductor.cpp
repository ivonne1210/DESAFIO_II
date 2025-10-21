#include "reproductor.h"
#include <iostream>

Reproductor::Reproductor() {
    actual = nullptr;
    reproduciendo = false;
    indiceActual = -1;
    repetir = false;
    srand(time(NULL)); // inicializar aleatoriedad
}

void Reproductor::reproducirAleatorio(Cancion* canciones[], int totalCanciones, Usuario* u) {
    if (totalCanciones <= 0) {
        cout << "No hay canciones en este álbum.\n";
        return;
    }

    if (u->esPremium(u->member_type)) {
        cout << "Modo premium activado (aquí podrías implementar más opciones)...\n";
    } else {
        cout << "Usuario no premium: solo reproducción aleatoria disponible.\n";
        int randomIndex = rand() % totalCanciones;
        actual = canciones[randomIndex];
        indiceActual = randomIndex;
        reproduciendo = true;
        cout << "🎵 Reproduciendo aleatoriamente: " << actual->name << endl;
    }
}

void Reproductor::detener() {
    if (reproduciendo) {
        cout << "⏹️ Reproducción detenida: " << actual->name << endl;
        reproduciendo = false;
    } else {
        cout << "No hay reproducción activa.\n";
    }
}

void Reproductor::mostrarMenu(Cancion* canciones[], int totalCanciones, Usuario* u) {
    int opcion = 0;

    do {
        cout << "\n===== MENÚ DE REPRODUCCIÓN =====\n";
        if (!reproduciendo) {
            cout << "1. Reproducir aleatorio\n";
            cout << "2. Salir\n";
        } else {
            cout << "1. Detener\n";
            cout << "2. Salir\n";
        }
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (!reproduciendo) {
            switch (opcion) {
            case 1:
                reproducirAleatorio(canciones, totalCanciones, u);
                break;
            case 2:
                cout << "Saliendo del reproductor...\n";
                break;
            default:
                cout << "Opción no válida.\n";
            }
        } else {
            switch (opcion) {
            case 1:
                detener();
                break;
            case 2:
                cout << "Saliendo del reproductor...\n";
                break;
            default:
                cout << "Opción no válida.\n";
            }
        }
    } while (opcion != 2);
}
