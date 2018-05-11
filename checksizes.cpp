#include "functions.h"

int checkSizes(int matrix_one_columns, int matrix_two_rows) {

    if(matrix_one_columns != matrix_two_rows)
        return ERR_MATRICES_WRONG_SIZE;

    return OK;

}