/*
 * Agencia Vehicular
 * A01711368
 * Alfredo Alejandro Soto Herrera
 * 14/10/24
 * Esta clase define objeto de tipo vehiculo.
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include <iostream>
#include <string>
using namespace std;

// Declaro la calse vehiculo
class Vehiculo {
// Declaro variables
protected:
  string marca;
  string modelo;
  double uso;
  int year;
  double valor_compra;

// Declaro los metodos de la clase
public:
  // Constructores
  Vehiculo() : marca("Na"), modelo("Na"), uso(10000), year(2013), 
  valor_compra(15000){};

  Vehiculo(string mar, string mod, double u, int yr, double val_com) : 
  marca(mar), modelo(mod), uso(u), year(yr), valor_compra(val_com){};

// Getters
  string getMarca(){
    return marca;
  };
  string getModelo(){
    return modelo;
  };
  double getUso(){
    return uso;
  };
  int getYear(){
    return year;
  };
  double getValorCompra(){
    return valor_compra;
  };
// Métodos
  void mostrar_info() const;
  double calcula_precio_venta() const;

};

/**
  * mostrar_info() imprime la información del vehiculo.
  *
  * Imprime la marca, modelo, uso y año.
  *
  *@param
  *@return void
*/
void Vehiculo :: mostrar_info() const {
  cout << "Marca: " << marca << endl;
  cout << "Modelo: " << modelo << endl;
  cout << "Uso: " << uso << " km" << endl;
  cout << "Year: " << year << endl;
  cout << "Precio de Venta: " << calcula_precio_venta() << endl;
  cout << endl;
  };


/**
  * calcular_precio_venta() en base al uso que haya tenido el vehiculo y el año
  * del modelo; calcula el precio de venta del vehiculo.
  *
  * Dependiendo de los valores de uso y año, se agrega valor al vehiculo o se 
  * le disminuye.
  *
  *@param
  *@return double del valor en el que se venderá el vehiculo.
*/
double Vehiculo :: calcula_precio_venta() const{
  double venta_inicial = valor_compra;
  if (uso < 20000){
    venta_inicial = venta_inicial + 10000;
  }
  else
    venta_inicial = venta_inicial - 500;
  if (year > 2020){
    venta_inicial = venta_inicial + 10000;
  }
  else
  venta_inicial = venta_inicial - 500;

  double venta_final = venta_inicial * 1.15;
  return venta_final;
};

#endif
