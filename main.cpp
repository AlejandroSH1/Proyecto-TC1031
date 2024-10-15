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

using namespace std;

int main() {
    ArbolBST agencia;
    string nombreArchivo = "vehiculos.csv"; 

    agencia.leerCSV(nombreArchivo);

    std::cout << "Vehiculos en orden por year:" << std::endl;
    agencia.inOrder();

    return 0;
}
