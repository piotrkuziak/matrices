#include "functions.h"

int createMatrix(int *rows, int *columns, int ***matrix) {

    if(rows == NULL || columns == NULL) {
        return ERR_WRONG_DATA;
    }

    *matrix = new (nothrow) int* [*rows];

    for(int i = 0; i < *rows; i++) *matrix[i] = new int [*columns];

    if(*matrix == nullptr) {
        return ERR_MEMORY_ALLOC_FAIL;
    }

    for(int i = 0; i < *rows; i++) {
        for(int j = 0; j < *columns; j++) *matrix[i][j] = 1;
    }

    for(int i = 0; i < *rows; i++) {
        cout << "[";
        for(int j = 0; j < *columns; j++) cout << " |" << *matrix[i][j] << "| ";
        cout << "]" << endl;
    }

    return OK;

}
