#include <string>
#include <sstream>
#include <iostream>
#include <filesystem>
#include <fstream>
#include "albumes.h"
#include "creditos.h"
#include "cancion.h"

namespace fs = std::filesystem;

using namespace std;

albumes::albumes(int _id, string _nom, string _sello, string _fecha, string _genero, int _dura, float _pun, string _portada){
    this->idAlbum = _id;
    this->nombre=_nom;
    this->selloDisquero=_sello;
    this->fechadelanzamiento=_fecha;
    this->duraciontotal=_dura;
    this->puntuacion=_pun;
    this->portadaRuta=_portada;
    this->totalCanciones =0;

    stringstream ss(_genero);
    string item;
    int i = 0;

    while (getline(ss, item, ',') && i < 4) {
        // Quitar espacios en blanco al inicio o final (opcional)
        if (!item.empty() && item[0] == ' ')
            item.erase(0, item.find_first_not_of(' '));
        this ->genero[i++] = item;
    }
    while (i < 4) {
        genero[i++] = "";
    }
}

void albumes::cargarCancionesDesdeArchivos(string carpetaRuta) {
    for (const auto& entry : fs::directory_iterator(carpetaRuta)) {
        string nombreArchivo = entry.path().filename().string();

        if (nombreArchivo.find(".txt") != string::npos && nombreArchivo != "Info_album.txt") {
            ifstream file(entry.path());
            if (!file.is_open()) continue;

            size_t id;
            string nombre, linea;
            int duracion = 0;
            Creditos creditos;

            while (getline(file, linea)) {
                if (linea.rfind("id=", 0) == 0) {
                    id = stoull(linea.substr(3));
                } else if (linea.rfind("nombre=", 0) == 0) {
                    nombre = linea.substr(7);
                } else if (linea.rfind("duracion=", 0) == 0) {
                    duracion = stoi(linea.substr(9));
                } else if (linea.rfind("productores=", 0) == 0) {
                    string sub = linea.substr(12);
                    size_t pos = 0;
                    while ((pos = sub.find(',')) != string::npos) {
                        string parte = sub.substr(0, pos);
                        size_t p = parte.find(':');
                        if (p != string::npos)
                            creditos.agregarProductor(parte.substr(0, p), "", parte.substr(p + 1));
                        sub.erase(0, pos + 1);
                    }
                    size_t p = sub.find(':');
                    if (p != string::npos)
                        creditos.agregarProductor(sub.substr(0, p), "", sub.substr(p + 1));
                } else if (linea.rfind("musicos=", 0) == 0) {
                    string sub = linea.substr(8);
                    size_t pos = 0;
                    while ((pos = sub.find(',')) != string::npos) {
                        string parte = sub.substr(0, pos);
                        size_t p = parte.find(':');
                        if (p != string::npos)
                            creditos.agregarMusico(parte.substr(0, p), "", parte.substr(p + 1));
                        sub.erase(0, pos + 1);
                    }
                    size_t p = sub.find(':');
                    if (p != string::npos)
                        creditos.agregarMusico(sub.substr(0, p), "", sub.substr(p + 1));
                } else if (linea.rfind("compositores=", 0) == 0) {
                    string sub = linea.substr(13);
                    size_t pos = 0;
                    while ((pos = sub.find(',')) != string::npos) {
                        string parte = sub.substr(0, pos);
                        size_t p = parte.find(':');
                        if (p != string::npos)
                            creditos.agregarCompositor(parte.substr(0, p), "", parte.substr(p + 1));
                        sub.erase(0, pos + 1);
                    }
                    size_t p = sub.find(':');
                    if (p != string::npos)
                        creditos.agregarCompositor(sub.substr(0, p), "", sub.substr(p + 1));
                }
            }

            file.close();

            // Ruta base igual para todas
            string rutaBase128 = carpetaRuta + "/" + nombre + "_128.ogg";
            string rutaBase320 = carpetaRuta + "/" + nombre + "_320.ogg";

            canciones[totalCanciones] = Cancion(id, nombre, duracion, rutaBase128, rutaBase320);
            canciones[totalCanciones].creditos = creditos;
            totalCanciones++;
        }
    }
}

void albumes::mostrarAlbum() {
    cout << "Album: " << nombre << " ===\n";
    for (int i = 0; i < totalCanciones; i++) {
        canciones[i].mostrarCancion();
    }
}

