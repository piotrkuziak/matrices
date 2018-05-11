#include "functions.h"

int multiplyMatrices(int** matrix_sizes, int*** matrix_array) {

    int **matrix_multiplied, rows = 0, columns = 0;

    if(matrix_sizes[0][1] != matrix_sizes[1][0])
        return ERR_MATRICES_WRONG_SIZE;

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < matrix_sizes[i][0]; j++) {
            for(int k = 0; k < matrix_sizes[i][1]; k++) {
                rows = matrix_sizes[i][0];
                columns = matrix_sizes[i][1];
                if(is_digit(to_string(matrix_array[i][rows][columns])) != OK)
                    return ERR_WRONG_DATA;
            }
        }
    }

    rows = matrix_sizes[0][0];
    columns = matrix_sizes[1][1];

    matrix_multiplied = new int* [rows];
    for(int i = 0; i < rows; i++)
        matrix_multiplied[i] = new int [columns];

    for(int i  = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) matrix_multiplied[i][j] = 0;
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            for(int k = 0; k < matrix_sizes[0][1]; k++)
                matrix_multiplied[i][j] += matrix_array[0][i][k] * matrix_array[1][k][j];
        }
    }

    matrix_sizes[2][0] = rows;
    matrix_sizes[2][1] = columns;
    matrix_array[2] = matrix_multiplied;

    return OK;

}