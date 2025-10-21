#include "reproductor.h"
#include "interfaz.h"
#include <iostream>
#include <chrono>
#include <thread>


Reproductor::Reproductor() {
    actual = nullptr;
    reproduciendo = false;
    indiceActual = -1;
    repetir = false;
    srand(time(NULL)); // inicializar aleatoriedad
}

void Reproductor::reproducirAleatorio(Cancion *canciones, int totalCanciones, Usuario u, Artista artista_actual, albumes album_actual) {
    using namespace std::chrono_literals;
    if (totalCanciones <= 0) {
        cout << "No hay canciones en este álbum.\n";
        return;
    }

    if (u.esPremium()) {
        cout << "Modo premium activado (aquí podrías implementar más opciones)...\n";
    } else {
        srand(time(nullptr));
        int Index_ant = totalCanciones;
        while(1){
        int randomIndex = rand() % totalCanciones;

        if(randomIndex == Index_ant){
            randomIndex ++;
        }

        actual = &canciones[randomIndex];
        indiceActual = randomIndex;
        Index_ant = randomIndex;

        Interfaz interfaz;
        interfaz.mostrarEstandar(artista_actual, album_actual, album_actual.canciones[randomIndex]);
        reproduciendo = true;
        std::this_thread::sleep_for(3s);
        }
    }
}

void Reproductor::reproducirSecuencial(Cancion* canciones, int totalCanciones, Usuario u, Artista artista_actual, albumes album_actual) {
    if (totalCanciones <= 0) {
        cout << "No hay canciones en este álbum.\n";
        return;
    }
    using namespace std::chrono_literals;
    int Index = 0;
    if (u.esPremium()) {
        cout << "Modo premium activado (aquí podrías implementar más opciones)...\n";
    } else {
        while(1){
        actual = &canciones[Index];
        indiceActual = Index;
        reproduciendo = true;
        Interfaz interfaz;
        interfaz.mostrarEstandar(artista_actual, album_actual, album_actual.canciones[Index]);
        cout << actual->name << endl;
        if (Index >= totalCanciones-1) Index = 0;
        else Index++;
        std::this_thread::sleep_for(3s);
        }
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
