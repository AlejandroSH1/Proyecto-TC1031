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

    int respuesta = 5;

    while(respuesta < 6){
        cout << "------------------------------" << endl;
        cout << "Escoge una opcion: " << endl;
        cout << "1) Mostrar lista de Vehiculos" << endl;
        cout << "2) Ordenar por precio de venta" << endl;
        cout << "3) Ordenar por anio" << endl;
        cout << "4) Buscar Vehiculo" << endl;
        cout << "5) Agregar Vehiculo" << endl;
        cout << "6) Salir" << endl;
        cout << "Responde con el numero de la opcion: " << endl;
        cin >> respuesta;
        cout << "------------------------------" << endl;

        if(respuesta == 1){
            for (size_t i = 0; i < vehiculos.size(); ++i) {
            vehiculos[i].mostrar_info();
            }
        }

        if(respuesta == 2){
            Sort bubbleVenta;
            bubbleVenta.bubbleSort_Venta(vehiculos);

            string impri;
            cout << "Imprimir la agencia ordenada? (si/no) "<< endl;
            cin >> impri;

            if(impri == "si"){
                for (size_t i = 0; i < vehiculos.size(); ++i) {
                    vehiculos[i].mostrar_info();
                }
            }
        }

        if(respuesta == 3){
            Sort bubbleYear;
            bubbleYear.bubbleSort_Year(vehiculos);

            string impri2;
            cout << "Imprimir la agencia ordenada? (si/no) "<< endl;
            cin >> impri2;

            if(impri2 == "si"){
                for (size_t i = 0; i < vehiculos.size(); ++i) {
                    vehiculos[i].mostrar_info();
                }
            }
        }

        if(respuesta == 4){
            int precio;
            cout << "Introduce el precio de venta del auto a buscar: " << endl;
            cin >> precio;

            const Vehiculo* vehiculoEncontrado = arbol.buscarVehiculo(precio);

            if (vehiculoEncontrado != nullptr) {
            cout << "Vehiculo encontrado: " << endl;
            vehiculoEncontrado->mostrar_info();
            } else {
            cout << "No se encontro un vehiculo con ese precio de venta." << std::endl;
            }   
        }

        if(respuesta == 5){
            arbol.agregaVehiculo();
            vehiculos = arbol.sortVe();
        }
    }

    return 0;
}
