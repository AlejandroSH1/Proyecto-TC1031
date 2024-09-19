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
#include "agencia.h"

using namespace std;

int main(){
  Agencia agencia;
  agencia.crea_agencia();
  agencia.ordena_precio();
  agencia.mostrar_info();

  return 0;
}