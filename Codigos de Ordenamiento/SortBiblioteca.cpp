#include <bits/stdc++.h>
using namespace std;

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
    int L[100], n, i=1, promedio=0;
    ifstream archivo; string lista;
    archivo.open("listas.txt");

    while( getline(archivo, lista) ){
        auto start = chrono::steady_clock::now();
        ArrXOrdenar( lista, L, n );
  
        // Sort the array in ascending order 
        std::sort(L, L + n);
  
        // Print the sorted array 
        for (int j = 0; j < n; j++) { cout << L[j] << " "; }
        cout << endl;
        auto end = chrono::steady_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        promedio+=duration;
        cout << i << ") Duración: " << duration << " nanosegundos" << endl; i++;
    }
    cout << "Duración Promedio: " << promedio/45 << endl;
    archivo.close();

    return 0; 
} 