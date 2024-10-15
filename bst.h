#ifndef BST_H
#define BST_H

#include "vehiculo.h"
#include <fstream>
#include <sstream>
#include <vector>

class NodoBST {
private:
    Vehiculo vehiculo;
    NodoBST* izquierda; 
    NodoBST* derecha; 
public:
    NodoBST(Vehiculo v) : vehiculo(v), izquierda(nullptr), derecha(nullptr) {}

    NodoBST* insertar(Vehiculo v);
    void inOrder();
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
void NodoBST::inOrder() {
    if (izquierda != nullptr) {
        izquierda->inOrder(); 
    }

    vehiculo.mostrar_info();

    if (derecha != nullptr) {
        derecha->inOrder();
    }
}


class ArbolBST {
private:
    NodoBST* raiz;

public:
    ArbolBST() : raiz(nullptr) {}
    void insertar(Vehiculo v);

    void inOrder();
    void leerCSV(const string& nombreArchivo);
};

void ArbolBST::insertar(Vehiculo v) {
    if (raiz == nullptr) {
        raiz = new NodoBST(v);
    } else {
        raiz->insertar(v);
    }
}

void ArbolBST::inOrder() {
    if (raiz != nullptr) {
        raiz->inOrder();
    } else {
        std::cout << "El árbol está vacío." << std::endl;
    }
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
