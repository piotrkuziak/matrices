#include "functions.h"

int populateMatrix(int rows, int columns, int** matrix_pointer, bool identity_matrix) {

    if(matrix_pointer == nullptr) {
        return ERR_MEMORY_ALLOC_FAIL;
    }

    if(identity_matrix) {
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++) {
                if(i == j)
                    matrix_pointer[i][j] = 1;
                else
                    matrix_pointer[i][j] = 0;
            }
        }
    } else {
        srand(time(NULL));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++) {
                matrix_pointer[i][j] = (rand() % 100) + 1;
            }
        }
    }

    return OK;

}