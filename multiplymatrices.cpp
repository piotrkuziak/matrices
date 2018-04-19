#include "functions.h"

int multiplyMatrices(int amount_of_matrices, int** matrix_sizes, int*** matrix_array) {

    for(int i = 0; i < amount_of_matrices; i++) {
        if(matrix_sizes[i][1] != matrix_sizes[i + 1][0]) return ERR_MATRICES_WRONG_SIZE;
    }

    return OK;

}