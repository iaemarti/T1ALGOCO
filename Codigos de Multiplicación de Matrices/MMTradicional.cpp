#include <bits/stdc++.h>
using namespace std;
int mfila;

// Función para convertir una cadena en un vector de enteros
vector<int> VecXOrdenar(string l) {
    vector<int> L;
    string aux;

    // Eliminar los corchetes al inicio y final de la cadena
    l = l.substr(1, l.length() - 2);

    // Mientras la cadena no esté vacía
    while (!l.empty()) {
        size_t i = l.find(',');

        // Si no se encuentra una coma, es el último número
        if (i == string::npos) {
            i = l.length();
        }

        aux = l.substr(0, i);

        // Eliminar espacios adicionales
        aux.erase(remove(aux.begin(), aux.end(), ' '), aux.end());

        // Verificar que el string no esté vacío antes de convertir a número
        if (!aux.empty()) {
            while( aux.find('{') == 0 ){ aux.erase(0,1); }
            while( aux.find('}') == aux.size()-1 ){ aux.erase(aux.size() - 1); }
            L.push_back(stoi(aux));
        }

        // Recortar la cadena para procesar el siguiente número
        l = l.substr(i + (i != l.length() ? 1 : 0));
    }
    return L;
}

int main() {
    int a[100][100], b[100][100], mul[100][100], i, j, k;
    ifstream archivo; 
    string linea;
    bool primeraMatriz = true; // Para alternar entre matrices
    int fila = 0;

    archivo.open("matrices.txt");

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    // Leer el archivo línea por línea
    while (getline(archivo, linea)) {
        // Si encontramos una línea en blanco, cambiamos a la segunda matriz
        if (linea.empty()) {
            primeraMatriz = false;
            fila = 0;
            continue;
        }

        // Convertir la línea a un vector de enteros
        vector<int> L = VecXOrdenar(linea);

        // Definir el número de filas según la longitud de L
        mfila = L.size();

        // Rellenar la matriz adecuada según el valor de `primeraMatriz`
        if (primeraMatriz) {
            for (j = 0; j < mfila; j++) {
                a[fila][j] = L[j];
                cout << L[j] << " ";
            }
            cout << endl;
        } else {
            for (j = 0; j < mfila; j++) {
                b[fila][j] = L[j];
                cout << L[j] << " ";
            }
            cout << endl;
        }
        fila++;
    }

    // Multiplicar las matrices
    cout << "Multiplicando las matrices...\n";
    for (i = 0; i < mfila; i++) {
        for (j = 0; j < mfila; j++) {
            mul[i][j] = 0;
            for (k = 0; k < mfila; k++) {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Imprimir el resultado de la multiplicación
    cout << "Resultado de la multiplicación de matrices:\n";
    for (i = 0; i < mfila; i++) {
        for (j = 0; j < mfila; j++) {
            cout << mul[i][j] << " ";
        }
        cout << "\n";
    }

    archivo.close();
    return 0;
}
