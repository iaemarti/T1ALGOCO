#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &vec, int low, int high) {

    // Selecciona al último elemento como pivote
    int pivot = vec[high];

    // Indice del elemento anterior al último
    // Se utiliza para intercambiar elementos
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // Si el elemento actual es
        // menor o igual al pivote
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    // Poner pivote en esta posición
    swap(vec[i + 1], vec[high]);

    // Retornar el punto de la partición
    return (i + 1);
}

void quickSort(vector<int> &vec, int low, int high) {

    // Mejor caso: Se ejecutará hasta que el indice
    // bajo inicial sea menor que el indice alto final
    if (low < high) {

        // pi el el indice de partición
        // arr[p] queda en el lugar correcto
        int pi = partition(vec, low, high);

        // Ordena elementos antes y después del
        // indice de particion pi por separado
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

vector<int> VecXOrdenar( string l ){
    vector<int> L; string aux;
    l = l.substr(1, l.length() - 2);

    while( !l.empty() ){
        size_t i = l.find(',');

        if (i == string::npos) { i = l.length(); }

        aux = l.substr(0, i);
        aux.erase(remove(aux.begin(), aux.end(), ' '), aux.end());

        L.push_back(stoi(aux));
        l = l.substr(i + (i != l.length() ? 1 : 0));    
    }
    return L;
}

int main(){
    // auto start = chrono::high_resolution_clock::now();
    ifstream archivo; string lista;
    archivo.open("listas.txt"); int i=1, promedio = 0;

    while( getline(archivo, lista) ){
        auto start = chrono::steady_clock::now();

        vector<int> vec = VecXOrdenar( lista );
        int n = vec.size();
    
        // Se llama quicksort respecto al vector vec
        quickSort(vec, 0, n - 1);
        for (auto i : vec) { cout << i << " "; }
        cout << endl;

        auto end = chrono::steady_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        promedio+=duration;
        cout << i << ") Duración: " << duration << " nanosegundos" << endl; i++;
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