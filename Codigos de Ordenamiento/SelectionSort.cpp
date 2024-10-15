#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {
    // Se recorre cada elemento no ordenado del subarreglo
    for (int i = 0; i < n - 1; i++) {
        // Encuentra el elemento mínimo del arreglo no ordenado
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Intercambia el elemento mínimo con el primero
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void ArrXOrdenar( string l, int L[], int&n ){
    string aux = l.substr(1, l.length() - 2);

    char cstr[aux.length() + 1];
    strcpy(cstr, aux.c_str());

    char* token = strtok(cstr, ",");
    n = 0;

    while (token != nullptr) {
        L[n++] = stoi(token);
        token = strtok(nullptr, ",");
    }
}

int main() {
    // auto start = chrono::high_resolution_clock::now();
    int L[100], n, promedio=0;
    ifstream archivo; string lista;
    archivo.open("listas.txt");

    while( getline(archivo, lista) ){
        auto start = chrono::steady_clock::now();

        ArrXOrdenar( lista, L, n );
        selectionSort(L, n);
        cout << "Sorted array: \n";
        printArray(L, n);

        auto end = chrono::steady_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        promedio+=duration;
        cout << "Duración: " << duration << " nanosegundos" << endl;
    }
    cout << "Duración Promedio: " << promedio/45 << endl;

    archivo.close();
    /*
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Duración: " << duration << " ms" << endl;
    */
    return 0;
}