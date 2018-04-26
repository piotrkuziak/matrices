#include "functions.h"

int createMatrix(int rows, int columns, int*** matrix_pointer) {

    if(rows == NULL || columns == NULL)
        return ERR_WRONG_DATA;

    int **matrix = new (nothrow) int* [rows];

    for(int i = 0; i < rows; i++) matrix[i] = new int [columns];

    if(matrix == nullptr)
        return ERR_MEMORY_ALLOC_FAIL;

    *matrix_pointer = matrix;

    return OK;

}
