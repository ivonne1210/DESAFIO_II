#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include "usuarios.h"
#include "artista.h"
#include "albumes.h"
#include "reproductor.h"
#include "ListaFavoritos.h"

using namespace std;
namespace fs = std::filesystem;

int main() {
    while(1){
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
                if(usuarioEncontrado.esPremium()){
                    while (1){
                    cout << "Ingrese la opcion que desea realizar: "<<endl<<"1) Reproduccir de forma aleatoria"<<endl<<"2) Acceder a la lista de favoritos"<<endl<<"3) Buscar otro usuario"<<endl;
                    int opcion = 0;
                    cin >> opcion;
                    switch(opcion){
                    case 1:{
                        Reproductor Rp = Reproductor();
                        Rp.reproducirAleatorio(usuarioEncontrado);
                        break;}
                    case 2:{
                        string rutaFavoritos = usuarioEncontrado.nick + "/favoritos.txt";
                        ListaFavoritos lista;
                        lista.cargarDesdeArchivo(rutaFavoritos);
                        while(1){
                        int opcion1 = 0;
                        cout << "========================================="<<endl;
                        cout << "Ingrese la accion que desea realizar " << endl;
                        cout << "1) Reproducir de manera aleatoria la lista de favoritos"<<endl;
                        cout << "2) Reproducir de manera secuencial la lista de favoritos"<<endl;
                        cout << "3) Regresar"<<endl;
                        cin >>opcion1;
                        switch (opcion1){
                        case 1:{
                            Reproductor Rp1 = Reproductor();
                            Rp1.reproducirAleatorioListaFav(usuarioEncontrado,&lista);
                            break;}
                        case 2:{
                            Reproductor Rp1 = Reproductor();
                            Rp1.reproducirSecuencialListaFav(usuarioEncontrado,&lista);
                            break;}
                        case 3:
                            break;
                        default:
                            cout << "Accion invalida"<<endl;
                            break;
                        }
                        if (opcion1==3) break;}
                        break;}
                    default:
                        cout << "Opcion invalida"<<endl;
                        break;
                        }
                    }
                }
                else{
                    cout << "Ingrese la opcion que desea realizar: "<<endl<<"1) Reproduccir de forma aleatoria"<<endl<<"2) Regresar"<<endl;
                    int opcion = 0;
                    cin >> opcion;
                    switch(opcion){
                    case 1:{
                        Reproductor Rp = Reproductor();
                        Rp.reproducirAleatorio(usuarioEncontrado);
                        break;}
                    case 2:
                        break;
                    default:
                        break;
                    }
                }
            }
        }

    }
    cout << "Usuario no registrado"<<endl;
    }
}
