/*
 * Agencia Vehicular
 * A01711368
 * Alfredo Alejandro Soto Herrera
 * 14/10/24
 * Esta archivo define la clase sort, la cual utiliza Bubble Sort para ordenar
 * el vector de la clase vehículo.
 */

#ifndef SORT_H
#define SORT_H

#include "bst.h"
#include "vehiculo.h"
#include <iostream>
#include <algorithm> // Nos permite hacer uso de la función swap.

// Declaro la clase Sort
class Sort{
public:
/**
  * bubbleSort(vector<Vehiculo>& vec) le aplica bubble sort al vector de los
  * vehículos de menor a mayor.
  *
  * Utilizando el método de Bubble sort, se ordena el vector.
  *
  * Complejidad temporal: O(n^2) en el peor de los casos.
  * Complejidad espacial: O(1).
  * 
  *@param vector
  *@return void
*/
    void bubbleSort(vector<Vehiculo>& vec) {
        int n = vec.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
            
                if (vec[j].calcula_precio_venta() > vec[j + 1].calcula_precio_venta()) {
                    swap(vec[j], vec[j + 1]); 
                }
            }
        }
    }
};
#endif
