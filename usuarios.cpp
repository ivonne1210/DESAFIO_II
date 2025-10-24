#include <string>
#include <fstream>
#include "iostream"
#include "usuarios.h"
using namespace std;

Usuario::Usuario(string _nick,int _member_type, string _city, string _country, string _regist){
    this->nick = _nick;
    this->member_type = _member_type;
    this->city = _city;
    this->country = _country;
    this->regist = _regist;
}

Usuario::Usuario() {
    this->nick = "";
    this->member_type = 0;
    this->city = "";
    this->country = "";
    this->regist = "";
}
bool Usuario::esPremium(){
    return member_type == 1;
}

void Usuario::mostrarUsuario() const {
    cout << "Nick: " << nick
         << "\nTipo: " << (member_type == 1 ? "Premium" : "Estandar")
         << "\nCiudad: " << city
         << "\nPais: " << country
         << "\nRegistro: " << regist << "\n\n";
}

bool Usuario::seguirLista(Usuario& otroUsuario, ListaFavoritos * ListaFav) {
    string nombreSeguidor = this->getNombre();
    string nombreSeguido = otroUsuario.getNombre();

    if (nombreSeguidor == nombreSeguido) {
        cout << "No puedes seguirte a ti mismo.\n";
        return false;
    }

    // Paso 1: verificar si ya sigue
    ifstream archivoLectura("Seguimientos.txt");
    string linea;
    while (getline(archivoLectura, linea)) {
        if (linea == nombreSeguidor + "|" + nombreSeguido) {
            cout << "Ya sigues al usuario " << nombreSeguido << ".\n";
            return false;
        }
    }

    archivoLectura.close();

    // Paso 2: seguir y registrar la relación
    ofstream archivoEscritura("Seguimiento.txt", ios::app);
    archivoEscritura << nombreSeguidor << "|" << nombreSeguido << "\n";
    archivoEscritura.close();

    cout << "Ahora sigues a " << nombreSeguido << ".\n";

    // Paso 3: copiar las canciones
    string rutaFavoritos = otroUsuario.nick + "/favoritos.txt";
    ListaFavoritos ListaOtro;
    ListaOtro.cargarDesdeArchivo(rutaFavoritos);

    if (ListaOtro.getCantidad() == 0) {
        cout << "El usuario seguido no tiene canciones favoritas.\n";
        return true;
    }

    for (int i = 0; i < ListaOtro.getCantidad(); ++i) {
        size_t idCancion = ListaOtro.getID(i);
        if (!ListaFav->existeID(idCancion)) {
            ListaFav->agregar(idCancion);
        }
    }
    return true;
}

void Usuario::dejarDeSeguir(const string& nombreSeguido) {
    ifstream entrada("Seguimiento.txt");
    ofstream salida("temp.txt");

    string linea;
    string clave = getNombre() + "|" + nombreSeguido;

    bool eliminado = false;
    while (getline(entrada, linea)) {
        if (linea != clave) {
            salida << linea << "\n";
        } else {
            eliminado = true;
        }
    }

    entrada.close();
    salida.close();
    remove("Seguimiento.txt");
    rename("temp.txt", "Seguimiento.txt");

    if (eliminado)
        cout << "Dejaste de seguir a " << nombreSeguido << ".\n";
    else
        cout << "No estabas siguiendo a " << nombreSeguido << ".\n";
}

