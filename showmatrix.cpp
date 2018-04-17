#include "functions.h"

void showMatrix(int rows, int columns, int** matrix_pointer) {

    for(int i = 0; i < rows; i++){
        cout << "[";
        for(int j = 0; j < columns; j++) {
            cout << " " << matrix_pointer[i][j] << " ";
        }
        cout << "]" << endl;
    }

}