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

    Metricas m;
    srand(time(nullptr));
    int cantidad = listaFav->getCantidad();
    int idxAnterior = -1;
    bool repetir = false, atras = false, detener = false;
    int idx = 0;

    size_t historial[6];
    int tamHist = 0;

    while (true) {
        m.reset();
        m.sumarMemoria(sizeof(cantidad));
        m.sumarMemoria(sizeof(idxAnterior));
        m.sumarMemoria(sizeof(repetir));
        m.sumarMemoria(sizeof(atras));
        m.sumarMemoria(sizeof(detener));
        m.sumarMemoria(sizeof(historial));
        m.sumarMemoria(sizeof(tamHist));
        m.sumarMemoria(sizeof(listaFav));
        m.sumarIteracion();

        if(!repetir && !atras && !detener){
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


        if (buscarCancion(id, art, alb, can, m)) {
            Interfaz inter;
            inter.mostrar(art, alb, can, detener);
            m.sumarMemoria(sizeof(id));
            m.sumarMemoria(sizeof(art));
            m.sumarMemoria(sizeof(alb));
            m.sumarMemoria(sizeof(can));
            m.sumarMemoria(sizeof(can.creditos));
            m.sumarMemoria(sizeof(inter));

            if (!repetir && !atras && !detener) {
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
            m.sumarMemoria(sizeof(opcion));
            m.sumarMemoria(sizeof(m));
            cin >> opcion;
            switch (opcion) {
            case 1:
                if(detener){
                    detener = false;
                    inter.mostrar(art, alb, can, detener);}
                this_thread::sleep_for(3s);
                m.sumarMemoria(sizeof(*this));
                m.sumarMemoria(sizeof(u));
                m.mostrar();
                this_thread::sleep_for(3s);
                break;
            case 2:
                detener = true;
                m.sumarMemoria(sizeof(*this));
                m.sumarMemoria(sizeof(u));
                m.mostrar();
                this_thread::sleep_for(3s);
                break;
            case 3:
                m.sumarMemoria(sizeof(*this));
                m.sumarMemoria(sizeof(u));
                detener = false;
                m.mostrar();
                this_thread::sleep_for(3s);
                break;
            case 4:
                m.sumarMemoria(sizeof(*this));
                m.sumarMemoria(sizeof(u));
                detener = false;
                atras = true;
                m.mostrar();
                this_thread::sleep_for(3s);
                break;
            case 5:
                m.sumarMemoria(sizeof(*this));
                m.sumarMemoria(sizeof(u));
                detener = false;
                repetir = true;
                m.mostrar();
                this_thread::sleep_for(3s);
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
    Metricas m;
    srand(time(nullptr));
    int cantidad = listaFav->getCantidad();
    bool repetir = false, atras = false, primero = true, detener = false;
    int idx = 0;

    size_t historial[6];
    int tamHist = 0;

    while (true) {
        m.reset();
        m.sumarMemoria(sizeof(cantidad));
        m.sumarMemoria(sizeof(repetir));
        m.sumarMemoria(sizeof(atras));
        m.sumarMemoria(sizeof(primero));
        m.sumarMemoria(sizeof(detener));
        m.sumarMemoria(sizeof(idx));
        m.sumarMemoria(sizeof(historial));
        m.sumarMemoria(sizeof(tamHist));
        m.sumarIteracion();

        if(!repetir && !atras && !primero && !detener){
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
        if (buscarCancion(id, art, alb, can, m)) {
            Interfaz inter;
            inter.mostrar(art, alb, can, detener);
            inter.mostrar(art, alb, can, detener);
            m.sumarMemoria(sizeof(id));
            m.sumarMemoria(sizeof(art));
            m.sumarMemoria(sizeof(alb));
            m.sumarMemoria(sizeof(can));
            m.sumarMemoria(sizeof(can.creditos));
            m.sumarMemoria(sizeof(inter));


            if (!repetir && !atras && !detener) {
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
            m.sumarMemoria(sizeof(opcion));
            cin >> opcion;
            switch (opcion) {
            case 1:
                if(detener){
                    detener = false;
                    inter.mostrar(art, alb, can, detener);
                }
                this_thread::sleep_for(3s);
                m.sumarMemoria(sizeof(*this));
                m.sumarMemoria(sizeof(u));
                m.mostrar();
                this_thread::sleep_for(3s);
                break;
            case 2:
                detener = true;
                m.sumarMemoria(sizeof(*this));
                m.sumarMemoria(sizeof(u));
                m.mostrar();
                this_thread::sleep_for(3s);
                break;
            case 3:
                detener = false;
                m.sumarMemoria(sizeof(*this));
                m.sumarMemoria(sizeof(u));
                m.mostrar();
                this_thread::sleep_for(3s);
                break;
            case 4:
                detener = false;
                atras = true;
                m.sumarMemoria(sizeof(*this));
                m.sumarMemoria(sizeof(u));
                m.mostrar();
                this_thread::sleep_for(3s);
                break;
            case 5:
                detener = false;
                repetir = true;
                m.sumarMemoria(sizeof(*this));
                m.sumarMemoria(sizeof(u));
                m.mostrar();
                this_thread::sleep_for(3s);
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
    Metricas m;

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

        bool repetir = false, atras = false, detener = false;
        int idx = 0;
        int idxAnterior = -1;
        size_t historial[6];
        int tamHist = 0;

        while (true){
            m.reset();
            m.sumarMemoria(sizeof(archivo));
            m.sumarMemoria(sizeof(cantidad));
            m.sumarMemoria(sizeof(linea));
            m.sumarMemoria(cantidad *sizeof(size_t));
            m.sumarMemoria(sizeof(i));

            m.sumarMemoria(sizeof(repetir));
            m.sumarMemoria(sizeof(atras));
            m.sumarMemoria(sizeof(detener));
            m.sumarMemoria(sizeof(idx));
            m.sumarMemoria(sizeof(idxAnterior));
            m.sumarMemoria(sizeof(historial));
            m.sumarMemoria(sizeof(tamHist));
            m.sumarIteracion();

            if(!repetir && !atras && !detener){
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
            if (buscarCancion(id, art, alb, can, m)) {
                Interfaz inter;
                inter.mostrar(art, alb, can, detener);
                m.sumarMemoria(sizeof(id));
                m.sumarMemoria(sizeof(art));
                m.sumarMemoria(sizeof(alb));
                m.sumarMemoria(sizeof(can));
                m.sumarMemoria(sizeof(can.creditos));
                m.sumarMemoria(sizeof(inter));

                if (!repetir && !atras && !detener) {
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
                m.sumarMemoria(sizeof(opcion));
                cin >> opcion;
                switch (opcion) {
                case 1:{
                    if(detener){
                        detener = false;
                        inter.mostrar(art, alb, can, detener);
                    }
                    this_thread::sleep_for(3s);
                    m.sumarMemoria(sizeof(*this));
                    m.sumarMemoria(sizeof(u));
                    m.mostrar();
                    this_thread::sleep_for(3s);
                    break;}
                case 2:
                    detener = true;
                    m.sumarMemoria(sizeof(*this));
                    m.sumarMemoria(sizeof(u));
                    m.mostrar();
                    this_thread::sleep_for(3s);
                    break;
                case 3:
                    detener = false;
                    m.sumarMemoria(sizeof(*this));
                    m.sumarMemoria(sizeof(u));
                    m.mostrar();
                    this_thread::sleep_for(3s);
                    break;
                case 4:
                    detener = false;
                    atras = true;
                    m.sumarMemoria(sizeof(*this));
                    m.sumarMemoria(sizeof(u));
                    m.mostrar();
                    this_thread::sleep_for(3s);
                    break;
                case 5:
                    detener = false;
                    repetir = true;
                    m.sumarMemoria(sizeof(*this));
                    m.sumarMemoria(sizeof(u));
                    m.mostrar();
                    this_thread::sleep_for(3s);
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
        bool detener = false;
        Publicidad anuncio = Publicidad();
        while(true){
            m.reset();
            m.sumarMemoria(sizeof(archivo));
            m.sumarMemoria(sizeof(cantidad));
            m.sumarMemoria(sizeof(linea));
            m.sumarMemoria(cantidad *sizeof(size_t));
            m.sumarMemoria(sizeof(i));

            m.sumarMemoria(sizeof(contadorPubli));
            m.sumarMemoria(sizeof(gestor));
            m.sumarMemoria(sizeof(idxAnterior));
            m.sumarMemoria(sizeof(idx));
            m.sumarMemoria(sizeof(detener));
            m.sumarMemoria(sizeof(anuncio));
            m.sumarIteracion();

            if(!detener){
                idx = rand() % cantidad;
                if (idx == idxAnterior) idx = (idx + 1) % cantidad;
                idxAnterior = idx;
                if(contadorPubli%3==0){
                    anuncio = gestor.obtenerAnuncio();
                }else{
                    anuncio = Publicidad();
                }
                contadorPubli++;
            }
            size_t id = ids[idx];
            Artista art;
            albumes alb;
            Cancion can;
            if (buscarCancion(id, art, alb, can, m)){
                Interfaz inter;
                inter.mostrar(art, alb, can, anuncio,detener);
                m.sumarMemoria(sizeof(id));
                m.sumarMemoria(sizeof(art));
                m.sumarMemoria(sizeof(alb));
                m.sumarMemoria(sizeof(can));
                m.sumarMemoria(sizeof(can.creditos));
                m.sumarMemoria(sizeof(inter));
                int opcion;
                cin >> opcion;
                m.sumarMemoria(sizeof(opcion));
                switch (opcion) {
                case 1:
                    if(detener){
                        detener = false;
                        inter.mostrar(art, alb, can, anuncio,detener);
                    }
                    this_thread::sleep_for(3s);
                    m.sumarMemoria(sizeof(*this));
                    m.sumarMemoria(sizeof(u));
                    m.mostrar();
                    this_thread::sleep_for(3s);
                    break;
                case 2:
                    detener = true;
                    m.sumarMemoria(sizeof(*this));
                    m.sumarMemoria(sizeof(u));
                    m.mostrar();
                    this_thread::sleep_for(3s);
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
    Metricas m;
    m.reset();
    if (buscarCancion(id_busqueda, art, alb, can, m)){
        Interfaz inter;
        inter.editarListaFav(art,alb,can);
        m.sumarIteracion();
        m.sumarMemoria(sizeof(art));
        m.sumarMemoria(sizeof(alb));
        m.sumarMemoria(sizeof(can));
        m.sumarMemoria(sizeof(can.creditos));
        m.sumarMemoria(sizeof(m));
        m.sumarMemoria(sizeof(*this));
        m.sumarMemoria(sizeof(id_busqueda));
        m.mostrar();
    }
    else {
        cout << "Cancion no encontrada"<<endl;
        return;
    }
}

bool Reproductor::buscarCancion(size_t idCancion, Artista &artista_out, albumes &album_out, Cancion &cancion_out, Metricas &m) {
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
/*
    m.sumarMemoria(sizeof(idArtista));
    m.sumarMemoria(sizeof(idAlbum));
    m.sumarMemoria(sizeof(archArtistas));
    m.sumarMemoria(sizeof(linea));
    m.sumarMemoria(sizeof(encontradoArtista));*/

    while (getline(archArtistas, linea)) {
        if (linea.empty()) continue;
        m.sumarIteracion();
        stringstream ss(linea);
        string idStr, nombre, edadStr, pais, seguidoresStr, posicionStr;
        getline(ss, idStr, '|');
        getline(ss, nombre, '|');
        getline(ss, edadStr, '|');
        getline(ss, pais, '|');
        getline(ss, seguidoresStr, '|');
        getline(ss, posicionStr, '|');

        size_t idA = stoi(idStr);
/*
        m.sumarMemoria(sizeof(ss));
        m.sumarMemoria(sizeof(idStr));
        m.sumarMemoria(sizeof(idA));
        m.sumarMemoria(sizeof(nombre));
        m.sumarMemoria(sizeof(edadStr));
        m.sumarMemoria(sizeof(pais));
        m.sumarMemoria(sizeof(seguidoresStr));
        m.sumarMemoria(sizeof(posicionStr));*/

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
/*
    m.sumarMemoria(sizeof(rutaAlbumes));
    m.sumarMemoria(sizeof(archAlbumes));*/

    bool encontradoAlbum = false;
    string lineaA;
/*
    m.sumarMemoria(sizeof(encontradoAlbum));
    m.sumarMemoria(sizeof(lineaA));*/

    while (getline(archAlbumes, lineaA)) {
        if (lineaA.empty()) continue;
        m.sumarIteracion();
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
/*
        m.sumarMemoria(sizeof(ss));
        m.sumarMemoria(sizeof(generostr));
        m.sumarMemoria(sizeof(datestr));
        m.sumarMemoria(sizeof(durstr));
        m.sumarMemoria(sizeof(namestr));
        m.sumarMemoria(sizeof(idAstr));
        m.sumarMemoria(sizeof(sellostr));
        m.sumarMemoria(sizeof(puntstr));
        m.sumarMemoria(sizeof(duracion));
        m.sumarMemoria(sizeof(idAlbum_A));
        m.sumarMemoria(sizeof(puntuacion));
        m.sumarMemoria(sizeof(portada));*/

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
/*
    m.sumarMemoria(sizeof(basePath));
    m.sumarMemoria(sizeof(encontradoCancion));*/

    for (const auto &songFile : fs::directory_iterator(basePath)) {
        if (!songFile.is_regular_file()) continue;
        if (songFile.path().extension() != ".txt") continue;

        ifstream archCancion(songFile.path());
        if (!archCancion) continue;
/*
        m.sumarMemoria(sizeof(fs::directory_iterator));
        m.sumarMemoria(sizeof(songFile));
        m.sumarMemoria(sizeof(archCancion));*/
        string lineaC;
        m.sumarMemoria(sizeof(lineaC));
        while (getline(archCancion, lineaC)) {
            if (lineaC.empty()) continue;
            m.sumarIteracion();
            stringstream ss(lineaC);
            string idSongstr, nameSongstr, duraSongstr, creditosstr;
            getline(ss, idSongstr, '|');
            getline(ss, nameSongstr, '|');
            getline(ss, duraSongstr, '|');
            getline(ss, creditosstr, '|');

            size_t idSongE = stoi(idSongstr);

/*
            m.sumarMemoria(sizeof(ss));
            m.sumarMemoria(sizeof(idSongstr));
            m.sumarMemoria(sizeof(nameSongstr));
            m.sumarMemoria(sizeof(duraSongstr));
            m.sumarMemoria(sizeof(creditosstr));
            m.sumarMemoria(sizeof(idSongE));*/

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
