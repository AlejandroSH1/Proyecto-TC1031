/*
 * Agencia Vehicular
 * A01711368
 * Alfredo Alejandro Soto Herrera
 * 18/09/24
 * Esta clase define objeto de tipo vehiculo que contiene las clases heredadas;
 * carro, motocicleta, cuatrimoto y bicicleta.
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include <iostream>
#include <string>
using namespace std;

// Declaro la calse vehiculo
class Vehiculo {
// Declaro variables de instancia
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
// Meétodos abstractos
  virtual void mostrar_info() = 0;
  virtual double calcula_precio_venta() = 0;

};

// Declaro la clase carro que hereda de Vehiculo
class Carro : public Vehiculo{
// Declaro variables de instancia
private:
  int num_puertas;
  string tipo_gasolina;
  double motor;

// Declaro los metodos de la clase
public:
// Constructores  
  Carro(): Vehiculo("Na", "Na", 10000, 2013, 15000){};
  Carro(string mar, string mod, double u, int yr, double val_com, int n_pue, 
  string tip_gas, double mot): Vehiculo(mar, mod, u, yr, val_com),
    num_puertas(n_pue),
    tipo_gasolina(tip_gas),
    motor(mot){};

  // Getters
  int getNumPuertas(){
    return num_puertas;
  };

  string getTipoGasolina(){
    return tipo_gasolina;
  };

  double getMotor(){
    return motor;
  };

  // Método para calcular un precio para la venta del carro
  double calcula_precio_venta();

  // Mostramos la información del carro
  void mostrar_info();
};

/**
  * calcular_precio_venta() en base al uso que haya tenido el carro, el año
  * del modelo, el número de puertas, el tipo de gasolina y el motor; calcula
  * el precio de venta del carro.
  *
  * Dependiendo de los valores de uso, año, puertas, gasolina y motor, se 
  * agrega valor al carro o se le disminuye.
  *
  *@param
  *@return double del valor en el que se venderá el carro.
*/
double Carro :: calcula_precio_venta(){
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
  if (num_puertas > 4){
    venta_inicial = venta_inicial + 10000;
  }
  else
    venta_inicial = venta_inicial - 500;
  if (tipo_gasolina == "roja"){
    venta_inicial = venta_inicial + 10000;
  }
  else
    venta_inicial = venta_inicial - 500;
  if (motor >= 2.0){
    venta_inicial = venta_inicial + 10000;
  }
  else
    venta_inicial = venta_inicial - 500;
  double venta_final = venta_inicial * 1.15;
  return venta_final;
};

/**
  * mostrar_info() imprime la información del carro.
  *
  * Imprime la marca, modelo, uso, año, número de puertas, tipo de gasolina
  * y motor.
  *
  *@param
  *@return void
*/
void Carro :: mostrar_info(){
  cout << "Marca: " << marca << endl;
  cout << "Modelo: " << modelo << endl;
  cout << "Uso: " << uso << " km" << endl;
  cout << "Anio: " << year << endl;
  cout << "Numero de puertas: " << num_puertas << endl;
  cout << "Tipo de gasolina: " << tipo_gasolina << endl;
  cout << "Motor: " << motor << " L" << endl;
};

class Motocicleta : public Vehiculo{
// Declaro variables de instancia
private:
  string tipo_moto;
  int motor;

// Declaro los metodos de la clase
public:
  // Constructores
  Motocicleta(): Vehiculo("Na", "Na", 10000, 2013, 15000){};
  Motocicleta(string mar, string mod, double u, int yr, double val_com, 
    string tip_mot, int mot) : Vehiculo(mar, mod, u, yr, val_com),
    tipo_moto(tip_mot),
    motor(mot){};

  // Getters
  string getTipoMoto(){
    return tipo_moto;
  };

  double getMotor(){
    return motor;
  };

  // Método para calcular un precio para la venta de una moto
  double calcula_precio_venta();

  // Mostramos la información general de la moto
  void mostrar_info();
};

/**
  * calcular_precio_venta() en base al uso que haya tenido la motocicleta, 
  * el año del modelo, el tipo de moto y el motor; calcula el precio de 
  * venta de la motocicleta.
  *
  * Dependiendo de los valores de uso, año, tipo de moto y motor, se 
  * agrega valor a la motocicleta o se le disminuye.
  *
  *@param
  *@return double del valor en el que se venderá la motocicleta.
*/
double Motocicleta :: calcula_precio_venta(){
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
  if (tipo_moto == "deportiva"){
    venta_inicial = venta_inicial + 10000;
  }
  else
    venta_inicial = venta_inicial - 500;
  if (motor >= 450){
    venta_inicial = venta_inicial + 10000;
  }
  else
    venta_inicial = venta_inicial - 500;
  double venta_final = venta_inicial * 1.15;
  return venta_final;
};

/**
  * mostrar_info() imprime la información de la motocicleta.
  *
  * Imprime la marca, modelo, uso, año, tipo de moto y motor.
  * 
  * @param
  * @return void
*/
void Motocicleta :: mostrar_info(){
  cout << "Marca: " << marca << endl;
  cout << "Modelo: " << modelo << endl;
  cout << "Uso: " << uso << " km" << endl;
  cout << "Anio: " << year << endl;
  cout << "Tipo de moto: " << tipo_moto << endl;
  cout << "Motor: " << motor << " cc" << endl;
};

class Cuatrimoto : public Vehiculo{
// Declaro variables de instancia
private:
  int capacidad;
  string tipo_terreno;

// Declaro los metodos de la clase
public:
  // Constructores
  Cuatrimoto(): Vehiculo("Na", "Na", 10000, 2013, 15000){};
  Cuatrimoto(string mar, string mod, double u, int yr, double val_com, 
    int cap, string tip_ter): Vehiculo(mar, mod, u, yr, val_com),
    capacidad(cap),
    tipo_terreno(tip_ter){};

  // Getters
  int getCapacidad(){
    return capacidad;
  };

  string getTipoTerreno(){
    return tipo_terreno;
  };

  // Método para calcular un precio para la venta de una cuatrimoto
  double calcula_precio_venta();

  // Mostramos la información general de la cuatrimoto
  void mostrar_info();
};

/**
  * calcular_precio_venta() en base al uso que haya tenido la cuatrimoto, 
  * el año del modelo, la capacidad y el tipo de terreno; calcula el precio 
  * de venta de la cuatrimoto.
  *
  * Dependiendo de los valores de uso, año, capacidad y terreno, se agrega 
  * valor a la cuatrimoto o se le disminuye.
  *
  *@param
  *@return double del valor en el que se venderá la cuatrimoto.
*/
double Cuatrimoto :: calcula_precio_venta(){
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
  if (capacidad > 2){
    venta_inicial = venta_inicial + 10000;
  }
  else
    venta_inicial = venta_inicial - 500;
  if (tipo_terreno == "todo terreno"){
    venta_inicial = venta_inicial + 10000;
  }
  else
    venta_inicial = venta_inicial - 500;
  double venta_final = venta_inicial * 1.15;
  return venta_final;
};

/**
  * mostrar_info() imprime la información de la cuatrimoto.
  *
  * Imprime la marca, modelo, uso, año, capacidad y tipo de terreno.
  *
  * @param
  * @return void
*/
void Cuatrimoto :: mostrar_info(){
  cout << "Marca: " << marca << endl;
  cout << "Modelo: " << modelo << endl;
  cout << "Uso: " << uso << " km" << endl;
  cout << "Anio: " << year << endl;
  cout << "Numero de pasajeros: " << capacidad << endl;
  cout << "Tipo de terreno: " << tipo_terreno << endl;
};

class Bicicleta : public Vehiculo{
// Declaro variables de instancia
private:
  bool velocidades;
  string tipo;

// Declaro los metodos de la clase
public:
  // Constructores
  Bicicleta(): Vehiculo("Na", "Na", 10000, 2013, 15000){};
  Bicicleta(string mar, string mod, double u, int yr, double val_com, 
  bool vel, string tip): Vehiculo(mar, mod, u, yr, val_com),
    velocidades(vel),
    tipo(tip){};

  // Getters
  bool getVelocidades(){
    return velocidades;
  };

  string getTipo(){
    return tipo;
  };

  // Método para calcular un precio para la venta de una bicicleta
  double calcula_precio_venta();

  // Mostramos la información general de la bicileta
  void mostrar_info();
};

/**
  * calcular_precio_venta() en base al uso que haya tenido la bicicleta, 
  * el año del modelo, si tiene velocidades y el tipo de bicicleta; calcula
  * el precio de venta de la bicicleta.
  *
  * Dependiendo de los valores de uso, año, velocidades y el tipo, se 
  * agrega valor a la bicicleta o se le disminuye.
  *
  *@param
  *@return double del valor en el que se venderá la bicicleta.
*/
double Bicicleta :: calcula_precio_venta(){
  double venta_inicial = valor_compra;
  if (uso < 20000){
    venta_inicial = venta_inicial + 1000;
  }
  else
    venta_inicial = venta_inicial - 50;
  if (year > 2020){
    venta_inicial = venta_inicial + 1000;
  }
  else
  venta_inicial = venta_inicial - 50;
  if (velocidades == true){
    venta_inicial = venta_inicial + 1000;
  }
  else
    venta_inicial = venta_inicial - 50;
  if (tipo == "pista"){
    venta_inicial = venta_inicial + 1000;
  }
  else
    venta_inicial = venta_inicial - 500;
  double venta_final = venta_inicial * 1.15;
  return venta_final;
};

/**
  * mostrar_info() imprime la información de la bicicleta.
  * 
  * Imprime la marca, modelo, uso, año, si tiene velocidades y el tipo de
  * bicicleta.
  *
  * @param
  * @return void
*/
void Bicicleta :: mostrar_info(){
  cout << "Marca: " << marca << endl;
  cout << "Modelo: " << modelo << endl;
  cout << "Uso: " << uso << " km" << endl;
  cout << "Anio: " << year << endl;
  cout << "Velocidades: " << boolalpha << velocidades << endl;
  cout << "Tipo: " << tipo << endl;
};

#endif