#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include "usuarios.h"
#include "artista.h"
#include "albumes.h"
#include "reproductor.h"

using namespace std;
namespace fs = std::filesystem;

int main() {
    string usuario;
    cout << "Buenas por favor ingrese el nickname de usuario: " << endl;

    cin >> usuario;
    string datos_usuarios = "usuarios.txt";
    ifstream entrada(datos_usuarios);

    if (!entrada) {
        cerr << "Error al abrir el archivo de entrada." << endl;
        return 1;
    }

    string linea;
    while (getline(entrada, linea)) {
        if (linea.empty()) continue;

        stringstream ss(linea);
        string nick, tipoStr, city, country, regist;
        getline(ss, nick, '|');
        getline(ss, tipoStr, '|');
        getline(ss, city, '|');
        getline(ss, country, '|');
        getline(ss, regist, '|');

        int tipo = stoi(tipoStr);

        if(usuario == nick){
            cout << "Bienvenido usuario " + nick<<endl;
            Usuario usuarioEncontrado = Usuario(nick, tipo, city, country, regist);
            while (1){
                string artista;
                cout << "Ingrese el artista que desea escuchar: ";

                cin.ignore();
                getline(cin, artista);
                string rutaArtista = "Artistas/" + artista;
                string datos_artista = rutaArtista + "/Info_artista.txt";
                ifstream entrada(datos_artista);

                if (!entrada) {
                    cerr << "Error al abrir el archivo de entrada." << endl;
                    return 1;
                }

                string lineaA;
                while (getline(entrada, lineaA)) {
                    if (lineaA.empty()) continue;

                    stringstream sa(lineaA);
                    string idstr, agestr, country, followersstr, positionstr;
                    getline(sa, idstr, '|');
                    getline(sa, agestr, '|');
                    getline(sa, country, '|');
                    getline(sa, followersstr, '|');
                    getline(sa, positionstr, '|');

                    int id = stoi(idstr);
                    int age = stoi(agestr);
                    size_t followers = stoi(followersstr);
                    int position = stoi(positionstr);

                    Artista artis = Artista(artista,id,age,country,followers,position);

                    cout << "\nAlbumes disponibles de " << artista << ":\n";

                    for (const auto& albumDir : fs::directory_iterator(rutaArtista)) {
                        if (fs::is_directory(albumDir)) {
                            string nombreAlbum = albumDir.path().filename().string();
                            cout << " - " << nombreAlbum << endl;
                        }
                    }
                    cout << "\nIngrese el nombre del album: ";

                    string album;
                    getline(cin, album);

                    string rutaAlbum = rutaArtista + "/" + album;
                    string rutaAlbum_I = rutaAlbum + "/Info_album.txt";
                    ifstream entrada(rutaAlbum_I);

                    if (!entrada) {
                        cerr << "Error al abrir el archivo de entrada." << endl;
                        return 1;
                    }
                    string linea;
                    while (getline(entrada, linea)) {
                        if (linea.empty()) continue;

                        stringstream ss(linea);
                        string generostr, datestr, durstr, namestr, idAstr, sellostr, puntstr;
                        getline(ss, generostr, '|');
                        getline(ss, datestr, '|');
                        getline(ss, durstr, '|');
                        getline(ss, namestr, '|');
                        getline(ss, idAstr, '|');
                        getline(ss, sellostr, '|');
                        getline(ss, puntstr, '|');

                        int duracion = stoi(durstr);
                        int idAlbum = stoi(idAstr);
                        float puntuacion = stoi(puntstr);

                        string portada = rutaArtista + "/" + album + "/image.png";

                        albumes album_actual = albumes(idAlbum,namestr,sellostr,datestr,generostr,duracion,puntuacion,portada);
                        album_actual.cargarCancionesDesdeArchivos(rutaAlbum);
                        while(1){
                            Reproductor r1 = Reproductor();
                            cout << "Desea reproducir en Forma: "<<endl<<"1) Aleatoria"<<endl<<"2) Secuencial"<<endl<<"3)Regresar";
                            int forma;
                            cin >> forma;
                            switch (forma) {
                            case 1:
                                r1.reproducirAleatorio(album_actual.canciones,album_actual.totalCanciones,usuarioEncontrado,artis,album_actual);
                                break;
                            case 2:
                                r1.reproducirSecuencial(album_actual.canciones,album_actual.totalCanciones,usuarioEncontrado,artis,album_actual);
                                break;
                            case 3:
                                break;
                            default:
                                cout << "Opcion invalida"<<endl;
                                break;
                            }
                        }
                    }
                }
            }
        }

    }
    cout << "Usuario no registrado"<<endl;
}
