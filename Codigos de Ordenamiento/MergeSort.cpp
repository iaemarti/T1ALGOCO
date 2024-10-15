#include <bits/stdc++.h>
using namespace std;

void printl(vector<int> avector) {
    for (unsigned int i=0; i<avector.size(); i++) {
        cout << avector[i] << " ";
    }
    cout << endl;
}

vector<int> mergeSort(vector<int> avector) {
    cout<<"Splitting ";
    printl(avector);
    if (avector.size()>1) {
        int mid = avector.size()/2;
        vector<int> lefthalf(avector.begin(),avector.begin()+mid);
        vector<int> righthalf(avector.begin()+mid,avector.begin()+avector.size());

        lefthalf = mergeSort(lefthalf);
        righthalf = mergeSort(righthalf);

        unsigned i = 0;
        unsigned j = 0;
        unsigned k = 0;
        while (i < lefthalf.size() && j < righthalf.size()) {
            if (lefthalf[i] < righthalf[j]) {
                avector[k]=lefthalf[i];
                i++;
            } else {
                avector[k] = righthalf[j];
                j++;
            }
            k++;
        }

        while (i<lefthalf.size()) {
            avector[k] = lefthalf[i];
            i++;
            k++;
        }

        while (j<righthalf.size()) {
            avector[k]=righthalf[j];
            j++;
            k++;
        }

    }
    cout<<"Merging ";
    printl(avector);

    return avector;
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

int main() {
    // auto start = chrono::high_resolution_clock::now();
    int i=1, promedio = 0;
    ifstream archivo; string lista;
    archivo.open("listas.txt");

    while( getline(archivo, lista) ){
        auto start = chrono::steady_clock::now();

        vector<int> avector = VecXOrdenar(lista);
        printl(mergeSort(avector));

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