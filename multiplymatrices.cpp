#include "functions.h"

int multiplyMatrices(int* matrix_sizes, int** matrix_one, int** matrix_two, int*** matrix_multiplied) {

    if(matrix_sizes[1] != matrix_sizes[2]) return ERR_MATRICES_WRONG_SIZE;

    int **new_matrix = new int* [matrix_sizes[0]];

    for(int i = 0; i < matrix_sizes[0]; i++) new_matrix[i] = new int [matrix_sizes[3]];

    for(int i = 0; i < matrix_sizes[0]; i++) {
        for(int j = 0; j < matrix_sizes[3]; j++) new_matrix[i][j] = 0;
    }

    for(int i = 0; i < matrix_sizes[0]; i++) {
        for(int j = 0; j < matrix_sizes[3]; j++) {
            for(int k = 0; k < matrix_sizes[1]; k++) {
                new_matrix[i][j] += matrix_one[i][k] * matrix_two[k][j];
            }
        }
    }

    *matrix_multiplied = new_matrix;

    return OK;

}