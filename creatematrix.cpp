#include "functions.h"

void createMatrix(int *rows, int *columns) {

    //int **matrix = new int*[*rows];
    //for(int i = 0; i < *rows; ++i) matrix[i] = new int[*columns];
    vector<int> matrix(*rows, 0);

    populateMatrix(matrix);

}
