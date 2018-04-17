#include "functions.h"

int populateMatrix(int rows, int columns, int** matrix_pointer) {

    if(matrix_pointer == nullptr) {
        return ERR_MEMORY_ALLOC_FAIL;
    }

    srand(time(NULL));

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++) {
            matrix_pointer[i][j] = (rand() % 100) + 1;
        }
    }

    return OK;

}