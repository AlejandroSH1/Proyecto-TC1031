/*
 * Agencia Vehicular
 * A01711368
 * Alfredo Alejandro Soto Herrera
 * 14/10/24
 * Esta archivo define la clase de nodo y de árbol BST, para poder guardar la 
 * lectura del archivo en una estructura de árbol.
 */

#ifndef BST_H
#define BST_H

#include "vehiculo.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Declaro la clase NodoBST
class NodoBST {
// Declaro las variables    
private:
    Vehiculo vehiculo;
    NodoBST* izquierda; 
    NodoBST* derecha; 
// Declaro los métodos de la clase
public:
    // Constructor
    NodoBST(Vehiculo v) : vehiculo(v), izquierda(nullptr), derecha(nullptr) {}
    // Métodos
    NodoBST* insertar(Vehiculo v);
    void inOrder(vector<Vehiculo>&) const;
};

/**
  * insertar(Vehiculo v) le agrega un vehiculo al arbol, esta es una función 
  * auxiliar a utilizar en la clase ArbolBST.
  *
  * Checa el año del vehiculo, para ordenarlo como hijo a la izquierda o si es
  * más grande a la derecha, en ambos casos se corrobora que exista un nodo.
  *
  * Complejidad temporal: O(log n) en el mejor caso y O(n) en el peor caso.
  * Complejidad espacial: O(log n) en el mejor caso y O(n) en el peor caso.
  * 
  *@param Vehiculo
  *@return this (regresa el apuntador del nodo en el que se realizó la llamada)
*/
NodoBST* NodoBST::insertar(Vehiculo v) {
    if (v.getYear() < vehiculo.getYear()) {
        if (izquierda == nullptr) {
            izquierda = new NodoBST(v);
        } else {
            izquierda = izquierda->insertar(v);
        }
    } else {
        if (derecha == nullptr) {
            derecha = new NodoBST(v);
        } else {
            derecha = derecha->insertar(v);
        }
    }
    return this;
}

/**
  * inOrder(vector<Vehiculo>& result) Ordena el árbol de tal forma que los nodos
  * queden de menor a mayor en base a su año.
  *
  * Recibe un vector y utiliza la recursión para checar los valores del árbol 
  * e irlos metiendo en este vector de forma ordenada.
  *
  * Complejidad temporal: O(n) en cualquier caso.
  * Complejidad espacial: O(log n) en el mejor caso y O(n) en el peor caso.
  * 
  *@param vector
  *@return void
*/
void NodoBST::inOrder(vector<Vehiculo>& result) const {
    if (izquierda != nullptr) {
            izquierda->inOrder(result);
        }
        result.push_back(vehiculo);
        if (derecha != nullptr) {
            derecha->inOrder(result);
        }
}

class ArbolBST {
private:
    NodoBST* raiz;

public:
    ArbolBST() : raiz(nullptr) {}
    void insertar(Vehiculo v);
    vector<Vehiculo> sortVe() const;
    void leerCSV(const string& nombreArchivo);
    void agregaVehiculo();
};

/**
  * insertar(Vehiculo v) utiliza la función auxiliar del NodoBST para agregar
  * valores al árbol.
  *
  * Primero revisa que la raíz no sea un valor nulo, para poder insertar 
  * valores.
  *
  * Complejidad temporal: O(log n) en el mejor caso y O(n) en el peor caso.
  * Complejidad espacial: O(log n) en el mejor caso y O(n) en el peor caso.
  * 
  *@param Vehiculo
  *@return void
*/
void ArbolBST::insertar(Vehiculo v) {
    if (raiz == nullptr) {
        raiz = new NodoBST(v);
    } else {
        raiz->insertar(v);
    }
}

/**
  * sortVe() utiliza la función inOrder(vector<Vehiculo>&) para poder pasar los
  * valores del árbol a un vector.
  *
  * Revisa que la raíz no sea un valor nulo y de esta forma aplicarle la función
  * inOrder(result) y regresar el vector ordenado.
  *
  * Complejidad temporal: O(n) en cualquier caso.
  * Complejidad espacial: O(n) en cualquier caso.
  * 
  *@param 
  *@return vector (El resultado de ordenar el árbol)
*/
vector<Vehiculo> ArbolBST :: sortVe() const {
    vector<Vehiculo> result;
        if (raiz != nullptr) {
            raiz->inOrder(result);
        }
        return result;
}

/**
  * leerCSV(const string& nombreArchivo) nos permite leer el archivo CSV con los
  * datos de los vehículos y ya con los datos leídos, crea los objetos 
  * Vehiculo y los agrega al árbol.
  *
  * Primero se revisa si el archivo se puede abrir, ya checado esto se leen los
  * valores y en caso de uso, valorCompra y year, se transforman de string a 
  * double, int y double respectivamente. Para finalmente concluir agregándolos
  * al árbol.
  *
  * Complejidad temporal: O(m log n) en el mejor caso y O(m n) en el peor caso.
  * Complejidad espacial: O(n) en cualquier caso.
  * 
  *@param string
  *@return void
*/
void ArbolBST::leerCSV(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string linea;

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string marca, modelo, usoStr, yearStr, valorCompraStr;
        double uso = 0.0, valorCompra = 0.0;
        int year = 0;

        try {
            getline(ss, marca, ',');
            getline(ss, modelo, ',');
            getline(ss, usoStr, ',');
            getline(ss, yearStr, ',');
            getline(ss, valorCompraStr, ',');

            uso = stod(usoStr);
            year = stoi(yearStr);
            valorCompra = stod(valorCompraStr);

            // Crea el vehículo y lo agrega al BST
            Vehiculo vehiculo(marca, modelo, uso, year, valorCompra);
            insertar(vehiculo);
        }
        catch (const invalid_argument& e) {
            continue; 
        }
    }
    archivo.close();
}

/**
  * agregaVehiculo() nos permite agregar un nuevo Vehiculo, brindado por el
  * usuario si este lo desea.
  *
  * Creamos las variables en donde se van a almacenar los valores y después se 
  * encuentran los cout´s y cin´s y finallmente se crea un objeto de tipo
  * Vehiculo con estos valores para después insertarlo al árbol.
  *
  * Complejidad temporal: O(log n) en el mejor caso y O(n) en el peor caso.
  * Complejidad espacial: O(1) para la función en sí.
  * 
  *@param
  *@return void
*/
void ArbolBST :: agregaVehiculo(){
    string marca, modelo;
    double uso, valorCompra;
    int year;
    
    cout << "Ingresa la marca: ";
    cin >> marca;
    cout << "Ingresa el modelo: ";
    cin >> modelo;
    cout << "Ingresa el kilometraje: ";
    cin >> uso;
    cout << "Ingresa el anio: ";
    cin >> year;
    cout << "Ingresa el precio de compra: ";
    cin >> valorCompra;

    Vehiculo vehi(marca, modelo, uso, year, valorCompra);
    insertar(vehi);
}

#endif
