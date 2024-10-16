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
};

void ArbolBST::insertar(Vehiculo v) {
    if (raiz == nullptr) {
        raiz = new NodoBST(v);
    } else {
        raiz->insertar(v);
    }
}

vector<Vehiculo> ArbolBST :: sortVe() const {
    vector<Vehiculo> result;
        if (raiz != nullptr) {
            raiz->inOrder(result);
        }
        return result;
}

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

            // Crear el vehículo y agregarlo al BST
            Vehiculo vehiculo(marca, modelo, uso, year, valorCompra);
            insertar(vehiculo);
        }
        catch (const invalid_argument& e) {
            continue; 
        }
    }
    archivo.close();
}

#endif
