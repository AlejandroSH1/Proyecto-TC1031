/*
 * Agencia Vehicular
 * A01711368
 * Alfredo Alejandro Soto Herrera
 * 18/09/24
 * Este proyecto consiste en la creación de un negocio o empresa, en el cual
 * se pueda crear un vehículo, ver los datos del vehículo y su valor de venta al
 * público.
 */

#include <iostream> // Para imprimir
// bicliotecas con las clases a utilizar en el proyecto.
#include "vehiculo.h"
#include "bst.h"
#include "sort.h"

using namespace std;

int main() {
    ArbolBST arbol;
    string nombreArchivo = "vehiculos.csv"; 

    arbol.leerCSV(nombreArchivo);

    vector<Vehiculo> vehiculos = arbol.sortVe();

    Sort bubble;
    bubble.bubbleSort(vehiculos);

    cout << "Vehiculos ordenados segun su precio de Venta: " << endl;
    for (size_t i = 0; i < vehiculos.size(); ++i) {
            vehiculos[i].mostrar_info();
            if (i != vehiculos.size() - 1) {
                cout << ",\n";
            }
        }

    return 0;
}
