#include "functions.h"

int checkSizes(int** matrix_sizes) {

    if(matrix_sizes[0][1] != matrix_sizes[1][0])
        return ERR_MATRICES_WRONG_SIZE;

    return OK;

}