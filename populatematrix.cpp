#include "functions.h"

int populateMatrix(int *rows, int *columns, int **matrix) {

//    random_device rd;
//    mt19937 mt(rd());
//    uniform_real_distribution<double> dist(1.00, 100.00);
//    dist(mt);

    for(int i = 0; i < *rows; i++) {
        for(int j = 0; j < *columns; j++) matrix[i][j] = 1;
    }

    for(int i = 0; i < *rows; i++) {
        cout << "[";
        for(int j = 0; j < *columns; j++) cout << " |" << matrix[i][j] << "| ";
        cout << "]" << endl;
    }

    return OK;

}