#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Funcion para verificar si un numero es primo
bool esPrimo(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Funcion para generar la serie de la primera fila (numeros triangulares)
vector<int> generarSerie1() {
    vector<int> serie;
    int suma = 0;
    for (int i = 1; i <= 10; ++i) {
        suma += i;
        serie.push_back(suma);
    }
    return serie;
}

// Funcion para generar la serie de la segunda fila (numeros primos)
vector<int> generarSerie2() {
    vector<int> serie;
    int contador = 0;
    int numero = 2;
    while (contador < 10) {
        if (esPrimo(numero)) {
            serie.push_back(numero);
            contador++;
        }
        numero++;
    }
    return serie;
}

// Funcion para generar la serie de la tercera fila (numeros de Fibonacci)
vector<int> generarSerie3() {
    vector<int> serie;
    int a = 0, b = 1;
    serie.push_back(a);
    serie.push_back(b);
    for (int i = 2; i < 10; ++i) {
        int temp = a + b;
        serie.push_back(temp);
        a = b;
        b = temp;
    }
    return serie;
}

// Funcion para encontrar el valor incorrecto en una fila
int encontrarValorIncorrecto(const vector<int>& fila, const vector<int>& serieCorrecta) {
    for (size_t i = 0; i < fila.size(); ++i) {
        if (fila[i] != serieCorrecta[i]) {
            return fila[i];
        }
    }
    return -1; // No se encontro ningun valor incorrecto
}

// Funcion para leer una fila de la matriz
vector<int> leerFila(int numeroFila) {
    string linea;
    vector<int> fila;
    while (true) {
        cout << "Ingrese los 10 valores de la fila " << numeroFila << " separados por espacio: ";
        getline(cin, linea);
        stringstream ss(linea);
        int valor;
        fila.clear();
        while (ss >> valor) {
            fila.push_back(valor);
        }
        if (fila.size() != 10) {
            cout << "Error: Debe ingresar exactamente 10 valores. Intentelo de nuevo." << endl;
        } else {
            break;
        }
    }
    return fila;
}

int main() {
    vector<int> matriz[3];
    vector<int> serie1 = generarSerie1();
    vector<int> serie2 = generarSerie2();
    vector<int> serie3 = generarSerie3();

    cout << "Objetivo: Descifrar el codigo en una matriz de 3x10 y encontrar el valor que no corresponde a las series respectivas." << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

    // Lectura de la matriz fila por fila
    matriz[0] = leerFila(1);
    matriz[1] = leerFila(2);
    matriz[2] = leerFila(3);

    // Encontrar los valores incorrectos
    int incorrecto1 = encontrarValorIncorrecto(matriz[0], serie1);
    int incorrecto2 = encontrarValorIncorrecto(matriz[1], serie2);
    int incorrecto3 = encontrarValorIncorrecto(matriz[2], serie3);

    // Imprimir el codigo
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\nEl codigo incorrecto es:" << endl;
    cout << incorrecto1 << "-" << incorrecto2 << "-" << incorrecto3 << endl;

    return 0;
}