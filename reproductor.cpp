#include <fstream>
#include <filesystem>
#include <iostream>
#include <thread>
#include "interfaz.h"
#include "reproductor.h"
#include "Gestor.h"
#include "publicidad.h"

namespace fs = std::filesystem;

Reproductor::Reproductor() {
    actual = nullptr;
    reproduciendo = false;
    indiceActual = -1;
    repetir = false;
    srand(time(NULL)); // inicializar aleatoriedad
}

void Reproductor::reproducirAleatorioListaFav(Usuario& u, ListaFavoritos* listaFav) {
    using namespace std::chrono_literals;

    if (!u.esPremium()) {
        cout << "Solo disponible para usuarios premium.\n";
        return;
    }

    if (!listaFav || listaFav->getCantidad() == 0) {
        cout << "No hay canciones en la lista de favoritos.\n";
        return;
    }

    srand(time(nullptr));
    int cantidad = listaFav->getCantidad();
    int idxAnterior = -1;
    bool repetir = false, atras = false;
    int idx = 0;

    size_t historial[6];
    int tamHist = 0;

    while (true) {

        if(!repetir && !atras){
        idx = rand() % cantidad;
        if (idx == idxAnterior) idx = (idx + 1) % cantidad;
        idxAnterior = idx;
        } else if(atras){
            if(tamHist>1){
                idx = historial[tamHist - 2];
                tamHist--;
            }else {
                cout << "No hay canciones anteriores.\n";
                atras = false;
                continue;
            }
        }

        size_t id = listaFav->getID(idx);
        Artista art;
        albumes alb;
        Cancion can;

        if (buscarCancion(id, art, alb, can)) {
            Interfaz inter;
            inter.mostrarPremiun(art, alb, can);

            if (!repetir && !atras) {
                if (tamHist == 0 || historial[tamHist - 1] != id) {
                    if (tamHist < 6) {
                        historial[tamHist++] = idx;
                    } else {
                        for (int i = 0; i < 5; ++i)
                            historial[i] = historial[i + 1];
                        historial[5] = idx;
                    }
                }
            }
            repetir = false;
            atras = false;

            int opcion;
            cin >> opcion;
            switch (opcion) {
            case 1:
                this_thread::sleep_for(3s);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                atras = true;
                break;
            case 5:
                repetir = true;
                break;
            case 6:
                cout << "Saliendo del reproductor\n";
                return;
                break;
            default:
                break;
            }
        } else {
            cout << "Saltando cancion no encontrada...\n";
        }
    }
}

void Reproductor::reproducirSecuencialListaFav(Usuario& u, ListaFavoritos* listaFav) {
    using namespace std::chrono_literals;

    if (!u.esPremium()) {
        cout << "Solo disponible para usuarios premium.\n";
        return;
    }

    if (!listaFav || listaFav->getCantidad() == 0) {
        cout << "No hay canciones en la lista de favoritos.\n";
        return;
    }

    srand(time(nullptr));
    int cantidad = listaFav->getCantidad();
    bool repetir = false, atras = false, primero = true;
    int idx = 0;

    size_t historial[6];
    int tamHist = 0;

    while (true) {

        if(!repetir && !atras && !primero){
            idx ++;
            if (idx == cantidad) idx = 0;
        } else if(atras){
            if(tamHist>1){
                idx = historial[tamHist - 2];
                tamHist--;
            }else {
                cout << "No hay canciones anteriores.\n";
                atras = false;
                continue;
            }
        }

        size_t id = listaFav->getID(idx);
        Artista art;
        albumes alb;
        Cancion can;

        if (buscarCancion(id, art, alb, can)) {
            Interfaz inter;
            inter.mostrarPremiun(art, alb, can);

            if (!repetir && !atras) {
                if (tamHist == 0 || historial[tamHist - 1] != id) {
                    if (tamHist < 6) {
                        historial[tamHist++] = idx;
                    } else {
                        for (int i = 0; i < 5; ++i)
                            historial[i] = historial[i + 1];
                        historial[5] = idx;
                    }
                }
            }
            repetir = false;
            atras = false;
            primero = false;

            int opcion;
            cin >> opcion;
            switch (opcion) {
            case 1:
                this_thread::sleep_for(3s);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                atras = true;
                break;
            case 5:
                repetir = true;
                break;
            case 6:
                cout << "Saliendo del reproductor\n";
                return;
                break;
            default:
                break;
            }
        } else {
            cout << "Saltando cancion no encontrada...\n";
        }
    }
}

void Reproductor::reproducirAleatorio(Usuario& u){

    ifstream archivo("Songs.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir songs.txt\n";
        return;
    }

    // Contar cuántas canciones hay
    int cantidad = 0;
    string linea;
    while (getline(archivo, linea)) {
        if (!linea.empty()) cantidad++;
    }

    if (cantidad == 0) {
        cout << "No hay canciones disponibles.\n";
        archivo.close();
        return;
    }
    size_t* ids = new size_t[cantidad];
    archivo.clear();
    archivo.seekg(0);
    int i = 0;

    while (getline(archivo, linea) && i < cantidad) {
        if (!linea.empty()) {
            ids[i] = stoull(linea);
            i++;
        }
    }
    archivo.close();

    if(u.esPremium()){

        bool repetir = false, atras = false;
        int idx = 0;
        int idxAnterior = -1;
        size_t historial[6];
        int tamHist = 0;

        while (true){
            if(!repetir && !atras){
                idx = rand() % cantidad;
                if (idx == idxAnterior) idx = (idx + 1) % cantidad;
                idxAnterior = idx;
            } else if(atras){
                if(tamHist>1){
                    idx = historial[tamHist - 2];
                    tamHist--;
                }else {
                    cout << "No hay canciones anteriores.\n";
                    atras = false;
                    continue;
                }
            }

            size_t id = ids[idx];
            Artista art;
            albumes alb;
            Cancion can;

            if (buscarCancion(id, art, alb, can)) {
                Interfaz inter;
                inter.mostrarPremiun(art, alb, can);

                if (!repetir && !atras) {
                    if (tamHist == 0 || historial[tamHist - 1] != id) {
                        if (tamHist < 4) {
                            historial[tamHist++] = idx;
                        } else {
                            for (int i = 0; i < 3; ++i)
                                historial[i] = historial[i + 1];
                            historial[3] = idx;
                        }
                    }
                }
                repetir = false;
                atras = false;

                int opcion;
                cin >> opcion;
                switch (opcion) {
                case 1:
                    this_thread::sleep_for(3s);
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    atras = true;
                    break;
                case 5:
                    repetir = true;
                    break;
                case 6:
                    delete [] ids;
                    cout << "Saliendo del reproductor\n";
                    return;
                    break;
                default:
                    break;
                }
            } else {
                cout << "Saltando cancion no encontrada...\n";
            }
        }
    }else{
        Gestor gestor;
        gestor.cargarDesdeArchivo("Publicidad.txt");
        int contadorPubli = 0;
        int idxAnterior = -1, idx = 0;
        while(true){
            Publicidad anuncio = Publicidad();
            idx = rand() % cantidad;
            if (idx == idxAnterior) idx = (idx + 1) % cantidad;
            idxAnterior = idx;

            if(contadorPubli%3==0){
                anuncio = gestor.obtenerAnuncio();
            }else{
            }
            contadorPubli++;
            size_t id = ids[idx];
            Artista art;
            albumes alb;
            Cancion can;
            if (buscarCancion(id, art, alb, can)){
                Interfaz inter;
                inter.mostrarEstandar(art, alb, can, anuncio);
                int opcion;
                cin >> opcion;
                switch (opcion) {
                case 1:
                    this_thread::sleep_for(3s);
                    break;
                case 2:
                    break;
                case 3:
                    //gestor.~Gestor();
                    delete [] ids;
                    return;
                default:
                    break;
                }
            }
        }
    }
}

void Reproductor::mostrarCancion(size_t id_busqueda){
    Artista art;
    albumes alb;
    Cancion can;

    if (buscarCancion(id_busqueda, art, alb, can)){
        Interfaz inter;
        inter.editarListaFav(art,alb,can);
    }
    else {
        cout << "Cancion no encontrada"<<endl;
        return;
    }
}

bool Reproductor::buscarCancion(size_t idCancion, Artista &artista_out, albumes &album_out, Cancion &cancion_out) {
    // Descomponer el ID
    size_t idArtista = idCancion / 10000;
    int idAlbum = (idCancion / 100) % 100;
    // === 1. Buscar ARTISTA ===
    ifstream archArtistas("Artistas.txt");
    if (!archArtistas) {
        cerr << "Error: no se pudo abrir Artistas.txt\n";
        return false;
    }

    string linea;
    bool encontradoArtista = false;

    while (getline(archArtistas, linea)) {
        if (linea.empty()) continue;

        stringstream ss(linea);
        string idStr, nombre, edadStr, pais, seguidoresStr, posicionStr;
        getline(ss, idStr, '|');
        getline(ss, nombre, '|');
        getline(ss, edadStr, '|');
        getline(ss, pais, '|');
        getline(ss, seguidoresStr, '|');
        getline(ss, posicionStr, '|');

        size_t idA = stoi(idStr);
        if (idA == idArtista) {
            int edad = stoi(edadStr);
            int seguidores = stoi(seguidoresStr);
            int posicion = stoi(posicionStr);
            artista_out = Artista(nombre, idA, edad, pais, seguidores, posicion);
            encontradoArtista = true;
            break;
        }
    }
    archArtistas.close();

    if (!encontradoArtista) {
        cout << "No se encontro el artista con ID " << idArtista << endl;
        return false;
    }

    // === 2. Buscar ÁLBUM ===
    string rutaAlbumes = "Artistas/" + artista_out.name + "/Albumes.txt";
    ifstream archAlbumes(rutaAlbumes);
    if (!archAlbumes) {
        cerr << "Error: no se pudo abrir " << rutaAlbumes << endl;
        return false;
    }

    bool encontradoAlbum = false;
    string lineaA;

    while (getline(archAlbumes, lineaA)) {
        if (lineaA.empty()) continue;

        stringstream ss(lineaA);
        string generostr, datestr, durstr, namestr, idAstr, sellostr, puntstr;
        getline(ss, generostr, '|');
        getline(ss, datestr, '|');
        getline(ss, durstr, '|');
        getline(ss, namestr, '|');
        getline(ss, idAstr, '|');
        getline(ss, sellostr, '|');
        getline(ss, puntstr, '|');

        int duracion = stoi(durstr);
        int idAlbum_A = stoi(idAstr);
        float puntuacion = stof(puntstr);
        string portada = "Artistas/" + artista_out.name + "/" + namestr + ".png";

        if (idAlbum == idAlbum_A) {
            album_out = albumes(idAlbum_A, namestr, sellostr, datestr, generostr, duracion, puntuacion, portada);
            encontradoAlbum = true;
            break;
        }
    }
    archAlbumes.close();

    if (!encontradoAlbum) {
        cout << "No se encontro el album con ID " << idAlbum << " para " << artista_out.name << endl;
        return false;
    }

    // === 3. Buscar CANCIÓN ===
    string basePath = "Artistas/" + artista_out.name + "/" + album_out.nombre + "/";
    bool encontradoCancion = false;

    for (const auto &songFile : fs::directory_iterator(basePath)) {
        if (!songFile.is_regular_file()) continue;
        if (songFile.path().extension() != ".txt") continue;

        ifstream archCancion(songFile.path());
        if (!archCancion) continue;

        string lineaC;
        while (getline(archCancion, lineaC)) {
            if (lineaC.empty()) continue;

            stringstream ss(lineaC);
            string idSongstr, nameSongstr, duraSongstr, creditosstr;
            getline(ss, idSongstr, '|');
            getline(ss, nameSongstr, '|');
            getline(ss, duraSongstr, '|');
            getline(ss, creditosstr, '|');

            size_t idSongE = stoi(idSongstr);
            if (idSongE == idCancion) {
                int duracion = stoi(duraSongstr);
                string ruta320 = basePath + nameSongstr + "_320.ogg";
                string ruta128 = basePath + nameSongstr + "_128.ogg";
                cancion_out = Cancion(idSongE, nameSongstr, duracion, ruta128, ruta320);
                cancion_out.creditos.cargarDesdeString(creditosstr);
                encontradoCancion = true;
                break;
            }
        }

        archCancion.close();
        if (encontradoCancion) break;
    }

    if (!encontradoCancion) {
        cout << "No se encontro la cancion con ID " << idCancion << endl;
        return false;
    }

    return true;
}

