#include <bits/stdc++.h>
using namespace std;

#define ROW_1 4
#define COL_1 4

#define ROW_2 4
#define COL_2 4

void print(string display, vector<vector<int>> matrix,
           size_t start_row, size_t start_column, size_t end_row,
           size_t end_column)
{
    cout << endl << display << " =>" << endl;
    for (size_t i = start_row; i <= end_row; i++) {
        for (size_t j = start_column; j <= end_column; j++) {
            cout << setw(10);
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void add_matrix(const vector<vector<int>>& matrix_A,
                const vector<vector<int>>& matrix_B,
                vector<vector<int>>& matrix_C,
                size_t split_index)
{
    for (size_t i = 0; i < split_index; i++)
        for (size_t j = 0; j < split_index; j++)
            matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
}

vector<vector<int>> multiply_matrix(const vector<vector<int>>& matrix_A,
                                    const vector<vector<int>>& matrix_B)
{
    size_t col_1 = matrix_A[0].size();
    size_t row_1 = matrix_A.size();
    size_t col_2 = matrix_B[0].size();
    size_t row_2 = matrix_B.size();

    if (col_1 != row_2) {
        cout << "\nError: The number of columns in Matrix "
                "A must be equal to the number of rows in "
                "Matrix B\n";
        return {};
    }

    vector<int> result_matrix_row(col_2, 0);
    vector<vector<int>> result_matrix(row_1, result_matrix_row);

    if (col_1 == 1)
        result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];
    else {
        size_t split_index = col_1 / 2;

        vector<int> row_vector(split_index, 0);
        vector<vector<int>> result_matrix_00(split_index, row_vector);
        vector<vector<int>> result_matrix_01(split_index, row_vector);
        vector<vector<int>> result_matrix_10(split_index, row_vector);
        vector<vector<int>> result_matrix_11(split_index, row_vector);

        vector<vector<int>> a00(split_index, row_vector);
        vector<vector<int>> a01(split_index, row_vector);
        vector<vector<int>> a10(split_index, row_vector);
        vector<vector<int>> a11(split_index, row_vector);
        vector<vector<int>> b00(split_index, row_vector);
        vector<vector<int>> b01(split_index, row_vector);
        vector<vector<int>> b10(split_index, row_vector);
        vector<vector<int>> b11(split_index, row_vector);

        for (size_t i = 0; i < split_index; i++)
            for (size_t j = 0; j < split_index; j++) {
                a00[i][j] = matrix_A[i][j];
                a01[i][j] = matrix_A[i][j + split_index];
                a10[i][j] = matrix_A[split_index + i][j];
                a11[i][j] = matrix_A[i + split_index][j + split_index];
                b00[i][j] = matrix_B[i][j];
                b01[i][j] = matrix_B[i][j + split_index];
                b10[i][j] = matrix_B[split_index + i][j];
                b11[i][j] = matrix_B[i + split_index][j + split_index];
            }

        add_matrix(multiply_matrix(a00, b00),
                   multiply_matrix(a01, b10),
                   result_matrix_00, split_index);
        add_matrix(multiply_matrix(a00, b01),
                   multiply_matrix(a01, b11),
                   result_matrix_01, split_index);
        add_matrix(multiply_matrix(a10, b00),
                   multiply_matrix(a11, b10),
                   result_matrix_10, split_index);
        add_matrix(multiply_matrix(a10, b01),
                   multiply_matrix(a11, b11),
                   result_matrix_11, split_index);

        for (size_t i = 0; i < split_index; i++)
            for (size_t j = 0; j < split_index; j++) {
                result_matrix[i][j] = result_matrix_00[i][j];
                result_matrix[i][j + split_index] = result_matrix_01[i][j];
                result_matrix[split_index + i][j] = result_matrix_10[i][j];
                result_matrix[i + split_index][j + split_index] = result_matrix_11[i][j];
            }
    }
    return result_matrix;
}

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
            while (aux.find('{') == 0) {
                aux.erase(0, 1);
            }
            while (aux.find('}') == aux.size() - 1) {
                aux.erase(aux.size() - 1);
            }
            L.push_back(stoi(aux));
        }

        // Recortar la cadena para procesar el siguiente número
        l = l.substr(i + (i != l.length() ? 1 : 0));
    }
    return L;
}

bool esPotenciaDe2(int x) {
    return (x > 0) && ((x & (x - 1)) == 0);
}

int main() {
    ifstream archivo;
    string linea;
    bool primeraMatriz = true; // Variable para controlar cuál matriz estamos llenando
    vector<vector<int>> matrix_A, matrix_B;

    archivo.open("matrices.txt");

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    while (getline(archivo, linea)) {
        // Si encontramos una línea en blanco, cambiamos a la segunda matriz
        if (linea.empty()) {
            primeraMatriz = false;
            continue;
        }

        // Convertir la línea a un vector de enteros
        vector<int> L = VecXOrdenar(linea);
        if(!esPotenciaDe2(static_cast<int>(L.size()))){ break; }

        // Rellenar la matriz adecuada según el valor de `primeraMatriz`
        if (primeraMatriz) {
            matrix_A.push_back(L); // Agregar la fila a la primera matriz
        } else {
            matrix_B.push_back(L); // Agregar la fila a la segunda matriz
        }
    }

    archivo.close();
    
    // Verificar las dimensiones de las matrices antes de imprimir y multiplicar
    if (matrix_A.empty() || matrix_B.empty()) {
        cerr << "Error: Una o ambas matrices están vacías." << endl;
        return 1;
    }

    print("Array A\n", matrix_A, 0, 0, matrix_A.size() - 1, matrix_A[0].size() - 1);
    print("Array B\n", matrix_B, 0, 0, matrix_B.size() - 1, matrix_B[0].size() - 1);

    vector<vector<int>> result_matrix = multiply_matrix(matrix_A, matrix_B);

    print("Result Array\n", result_matrix, 0, 0, result_matrix.size() - 1, result_matrix[0].size() - 1);

    return 0;
}
