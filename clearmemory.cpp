#include "functions.h"

void clearMemory(int rows, int** matrix) {

    for(int i = 0; i < rows; i++) delete[] matrix[i];
    delete[] matrix;

}

