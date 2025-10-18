#include <iostream>
#include <fstream>
#include <sstream>
#include "usuarios.h"
#include "Cancion.h"

using namespace std;

int main() {
    string datos_usuarios = "usuarios.txt";
    ifstream entrada(datos_usuarios);

    if (!entrada) {
        cerr << "Error al abrir el archivo de entrada." << endl;
        return 1;
    }

    Usuario* listaUsuarios = nullptr; // puntero al arreglo dinámico
    int cantidad = 0;                 // número actual de usuarios

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

        // 🧠 Crear nuevo arreglo con +1 espacio
        Usuario* temp = new Usuario[cantidad + 1];

        // Copiar usuarios anteriores al nuevo arreglo
        for (int i = 0; i < cantidad; i++)
            temp[i] = listaUsuarios[i];

        // Agregar el nuevo usuario al final
        temp[cantidad] = Usuario(nick, tipo, city, country, regist);

        // Liberar la memoria anterior y reasignar puntero
        delete[] listaUsuarios;
        listaUsuarios = temp;
        cantidad++;
    }
    entrada.close();

    // Mostrar todos los usuarios cargados
    cout << "\nUsuarios cargados desde el archivo (" << cantidad << "):\n";
    for (int i = 0; i < cantidad; i++) {
        listaUsuarios[i].mostrarUsuario();
    }

    // Liberar memoria final
    delete[] listaUsuarios;

    return 0;
}
