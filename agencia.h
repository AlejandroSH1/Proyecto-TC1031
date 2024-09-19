/*
 * Agencia Vehicular
 * A01711368
 * Alfredo Alejandro Soto Herrera
 * 18/09/24
 * Esta clase define objeto de tipo Agencia, la cual contiene un vector de
 * vehiculos.
 */

#ifndef AGENCIA_H
#define AGENCIA_H

#include <iostream>
#include "vehiculo.h"

using namespace std;

// Declaro la clase Agencia
class Agencia{
// Declaro variables de instancia
private:
  Vehiculo* vhc[100];
  int cantidad;
  double dinero;

// Declaro los metodos de la clase 
public:
  Agencia() : cantidad(0),dinero(500000){}; // Constructor por omisión

  void crea_agencia();

  void ordena_precio();

  void mostrar_info();
};

/**
  * crea_agencia() crea 5 vehiculos a la agencia, con el objetivo de no tener 
  * que crear uno por uno.
  *
  * Agrega vehiculos al vector de vehiculos.
  *
  * @param
  * @return void
*/
void Agencia :: crea_agencia(){
  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  vhc[cantidad] = new Carro("Toyota" , "Corolla", 10000, 2013, 100000, 4, 
    "verde", 1.6);
  cantidad++;
  vhc[cantidad] = new Carro("BMW" , "Series 1", 50000, 2011, 200000, 4, 
    "verde", 2.0);
  cantidad++;
  vhc[cantidad] = new Motocicleta("Honda", "Choper", 20000, 2019, 230000, 
    "deportiva", 250);
  cantidad++;
  vhc[cantidad] = new Cuatrimoto("Suzuki", "GSX", 15000, 2022, 300000, 3, 
    "todo terreno");
  cantidad++;
  vhc[cantidad] = new Bicicleta("Caloi", "Cruiser", 5000, 2020, 90000, true, 
   "pista");
  cantidad++;
};

/**
  * ordena_precio() ordena la agencia por precio de venta del vehículo, de menor
  * a mayor.
  *  
  * Utilizando el método de BubbleSort, se ordena todo el vector de la agencia.
  * 
  * @param
  * 
  * @return void
*/
void Agencia :: ordena_precio(){
  for (int i = 0; i < cantidad - 1; i++){
    for (int j = 0; j < cantidad - i - 1; j++){
      if (vhc[j]->calcula_precio_venta() > vhc[j + 1]->calcula_precio_venta()){
        Vehiculo* aux = vhc[j];
        vhc[j] = vhc[j + 1];
        vhc[j + 1] = aux;
      }
    }
  }
};

/**
  * mostrar_info() imprime la información de todos los vehiculos del vector.
  *
  * Utiliza el método de mostrar_info() de cada objeto del vector de vehiculos,
  * para imprimir la información de cada uno de ellos.
  *
  * @param
  * @return void
*/
void Agencia :: mostrar_info(){
  /*
  Ciclo que recorre el arreglo e imprime cada objeto, además de el valor de 
  el valor de venta del vehiculo.
  */
  for (int i = 0; i < cantidad; i++){
    vhc[i]->mostrar_info();
    cout << "Valor de venta: " << vhc[i]->calcula_precio_venta() << endl;
    cout << endl;
  }
}  

#endif