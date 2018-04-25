#include "functions.h"

int multiplyMatrices(int amount_of_matrices, int** matrix_sizes, int*** matrix_array) {

    int **matrix_multiplied, rows = 0, columns = 0;

    for(int i = 0; i < amount_of_matrices; i++) {
        if(matrix_sizes[i][1] != matrix_sizes[i + 1][0]) return ERR_MATRICES_WRONG_SIZE;
    }

    rows = matrix_sizes[0][0];
    columns = matrix_sizes[amount_of_matrices - 1][1];

    matrix_multiplied = new int* [rows];
    for(int i = 0; i < rows; i++)
        matrix_multiplied[i] = new int [columns];

    for(int i  = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) matrix_multiplied[i][j] = 0;
    }

    return OK;

}