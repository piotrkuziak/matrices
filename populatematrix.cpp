#include "functions.h"
#include <stdlib.h>
#include <time.h>

void populateMatrix(int *matrix, int *rows, int *columns) {

    srand(time(NULL));

    for(int i = 0; i < *rows; i++){
        for(int j = 0; j < *columns; j++) matrix[i] = rand() % 100 + 1;
    }

}