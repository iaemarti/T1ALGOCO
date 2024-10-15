#include <bits/stdc++.h>
using namespace std;

vector<int> GenDSint(){
	int tamaño = rand()%100+1;
	vector<int> lista(tamaño);
	for( int i=0; i<tamaño; i++ ){
		lista[i] = rand()%2001-1000;
	}
	return lista;
}

int main(){
	ofstream archlistas;
	archlistas.open("listas.txt", ios::out);

	if(!archlistas){
		cout << "Error" << endl;
		return 0;
	}

	// Listas Desordenadas
	for( int i=0; i<15; i++){
		vector<int> DS = GenDSint();
		archlistas << "[";
		for( size_t j=0; j<DS.size(); j++ ){
			archlistas << DS[j];
			if( j+1 != DS.size() ){ archlistas << ", "; }
		}
		archlistas << "]" << endl;
	}

	// Listas Ordenadas
	for( int i=0; i<15; i++){
		vector<int> DS = GenDSint();
		sort(DS.begin(), DS.end());
		archlistas << "[";
		for( size_t j=0; j<DS.size(); j++ ){
			archlistas << DS[j];
			if( j+1 != DS.size() ){ archlistas << ", "; }
		}
		archlistas << "]" << endl;
	}

	// Listas Semi-Ordenadas
	for( int i=0; i<15; i++){
		vector<int> DS = GenDSint();
		sort(DS.begin(), DS.begin() + DS.size()/2);
		archlistas << "[";
		for( size_t j=0; j<DS.size(); j++ ){
			archlistas << DS[j];
			if( j+1 != DS.size() ){ archlistas << ", "; }
		}
		archlistas << "]" << endl;
	}

	archlistas.close();
	return 0;
}