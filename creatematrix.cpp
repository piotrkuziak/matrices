#include "functions.h"

int createMatrix(int *rows, int *columns) {

    if(*rows == NULL || *columns == NULL) {
        return ERR_WRONG_DATA;
    }

    int **matrix = new (nothrow) int* [*rows];

    for(int i = 0; i < *rows; i++) matrix[i] = new int [*columns];

    if(*matrix == nullptr) {
        return ERR_MEMORY_ALLOC_FAIL;
    }

    return OK;

}
