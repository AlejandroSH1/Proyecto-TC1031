# Proyecto-TC1031

### Alfredo Alejandro Soto Herrera
### A01711368

Repositorio en el que se encuentra el proyecto de la materia TC1031, incluyendo el main y los respectivos .h de este trabajo.
Este trabajo consiste en la creación de una agencia automovilística, en la cual se observan los datos del vehiculo y su precio de venta y en base a este precio se ordenan de menor a mayor.

## SICT0301: Evalúa los componentes

#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa
Debido a que se trata de un bubble, la complejidad temporal del algoritmo es de O(n^2) en el peor de los casos y su complejidad espacial es de O(1) siempre.

#### Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa
* La función mostrar_info() en vehiculo.h tiene complejidad temporal y espacial de O(1) ya que solo se imprime información.
* La función calcula_precio_venta() también tiene una complejidad temporal y espacial de O(1) ya que solo hace operaciones simples.
* insertar(Vehiculo v) en bst.h de la clase NodoBST tiene complejidad temporal de O(log n) en el mejor caso y O(n) en el peor caso y complejidad espacial de O(log n) en el mejor caso y O(n) en el peor caso. Todo esto dependiendo de si es un árbol balanceado o no.
* inOrder(vector<Vehiculo>& result) tiene una complejidad temporal O(n) en cualquier caso y una complejidad espacial O(log n) en el mejor caso y O(n) en el peor caso, dependiendo del tamaño del vector.
* insertar(Vehiculo v) de la clase ArbolBST es de una complejidad temporal de O(log n) en el mejor caso y O(n) en el peor caso y una complejidad espacial O(log n) en el mejor caso y O(n) en el peor caso, todo depende de si el árbol está balaneado.
* En la función sortVe() se tiene una complejidad temporal O(n) en cualquier caso y complejidad espacial O(n) en cualquier caso ya que depende del vector.
* En leerCSV(const string& nombreArchivo) hay complejidad temporal de O(m log n) en el mejor caso y O(m n) en el peor caso donde m es la ínea que se lee del csv y complejidad espacial O(n) en cualquier caso.
* Finalmente en agregaVehiculo() se tiene una complejidad temporal: O(log n) en el mejor caso y O(n) en el peor caso ya que depende de la inserción y una complejidad espacial: O(1) para la función en sí.

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa
La complejidad final del programa, en tiempo es de O(n log n + k log n) donde n es el número de vehículos y k son las incersiones por el usuario y su complejidad espacial es de 0(n) por los vectores usados.

## SICT0302: Toma decisiones

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente
El ordenamiento que utilicé fue bubble sort, debido a que la organización de los datos no requería de otro ordenamiento con mayor complejidad.

#### Selecciona una estructura de datos adecuada al problema y lo usa correctamente
La estructura de datos que utilicé fue un árbol BST ya que es algo muy simple de aplicar y en mi proyecto solo necesitaba hacer inserciones, por lo que no era necesario otra estructura con mayores acciones.

## SICT0303: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructras correctos
Se puede consultar la información, mostrando en la terminal los vehículos ordenados en la estructura.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta
Se encuentra un archivo llamado "vehiculos.csv" para de ahí sacar información para crear los vehiculos y guardarlos en el árbol.

#### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
Si el usuario llega a agregar un nuevo vehículo, este automáticamente se guardará en el archivo "vehiculos.csv".

> [!NOTE]
> Para compilar y correr en terminal de Windows: g++ main.cpp / a.exe

