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
// Bicliotecas con las clases a utilizar en el proyecto.
#include "vehiculo.h"
#include "bst.h"
#include "sort.h"

using namespace std;

int main() {
    // Creamos el objeto de clase ArbolBST.
    ArbolBST arbol;
    // Damos el nombre del archivo a leer.
    string nombreArchivo = "vehiculos.csv"; 

    arbol.leerCSV(nombreArchivo);

    // Creamos el vector en donde se guardan los datos del árbol.
    vector<Vehiculo> vehiculos = arbol.sortVe();

    // Aplicamos BubbleSort al vector.
    Sort bubble;
    bubble.bubbleSort(vehiculos);

    // Imprimimos el vector ordenado.
    cout << "Vehiculos ordenados segun su precio de Venta: " << endl;
    for (size_t i = 0; i < vehiculos.size(); ++i) {
            vehiculos[i].mostrar_info();
    }

    // Le preguntamos al usuario si desea agregar más vehículos.
    string agregar, entra;
    cout << "Deseas agregar un vehiculo? (si/no): ";
    cin >> agregar;
    if(agregar == "si") entra = "si"; {}

    while(agregar == "si"){
        arbol.agregaVehiculo();
        vehiculos = arbol.sortVe();
        cout << "\nDeseas agregar otro vehiculo? (si/no): ";
        cin >> agregar;
    }

    if (entra == "si"){
        // Finalmente preguntamos si se requiere volver a mostrar la lista.
        string mostrar;
        cout << "\nVolver a mostrar la lista de Vehiculos? (si/no): ";
        cin >> mostrar;

        if(mostrar == "si"){
            bubble.bubbleSort(vehiculos);
            cout << "\nVehiculos ordenados segun su precio de Venta: " << endl;
            for (size_t i = 0; i < vehiculos.size(); ++i) {
                vehiculos[i].mostrar_info();
            }
        }
    }

    return 0;
}
