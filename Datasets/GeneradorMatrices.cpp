#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > CreadorMatriz(int n){
    // la matriz tendrá tamaño nxn

    vector< vector<int> > M(n, vector<int>(n));
    for( int i=0; i<n; i++ ){
        vector<int> fila;
        for( int j=0; j<n; j++ ){ M[i][j] = rand()%20+1 ; }
    }

    return M;
}

bool esPotenciaDe2(int x) {
    return (x > 0) && ((x & (x - 1)) == 0);
}

int main(){
    srand(time(0));
    ofstream archmatrices;
    archmatrices.open("matrices.txt", ios::out);

    if(!archmatrices){
        cout << "Error" << endl;
        return 0;
    }

    int n;
    while(!esPotenciaDe2(n)) { n=rand()%2048+1;}
    for( int k=0; k<2; k++ ){
        vector< vector<int> > M = CreadorMatriz(n);
        archmatrices << "{ ";
        for( size_t i=0; i<M.size(); i++ ){
            vector<int> fila = M[i];
            archmatrices << "{ ";
            for( size_t j=0; j<M.size(); j++ ){
                archmatrices << fila[j];
                if( j+1!=M.size() ){ archmatrices << ", "; }
            } archmatrices << " }";
            if( i+1 != M.size() ){ archmatrices << "," << endl; }
        }
        archmatrices << " };" << endl;
        archmatrices << endl;
    }

    archmatrices.close();
    return 0;
}