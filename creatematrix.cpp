#include "functions.h"

int createMatrix(int *rows, int *columns, int ***matrix_passed) {

    if(*rows == NULL || *columns == NULL) {
        return ERR_WRONG_DATA;
    }

//    random_device rd;
//    mt19937 mt(rd());
//    uniform_real_distribution<double> dist(1.00, 100.00);

    int **matrix = new (nothrow) int* [*rows];

    for(int i = 0; i < *rows; i++) matrix[i] = new int [*columns];

    if(matrix == nullptr) {
        return ERR_MEMORY_ALLOC_FAIL;
    }

//    for(int i = 0; i < *rows; i++) {
//        for(int j = 0; j < *columns; j++) matrix[i][j] = dist(mt);
//    }
//
//    for(int i = 0; i < *rows; i++) {
//        cout << "[";
//        for(int j = 0; j < *columns; j++) cout << " " << matrix[i][j] << " ";
//        cout << "]" << endl;
//    }
//
//    cout << "=========================" << endl;

    *matrix_passed = matrix;

    return OK;

}
