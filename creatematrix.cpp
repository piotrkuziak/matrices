#include "functions.h"

void createMatrix(int *rows, int *columns) {

    vector<vector<int>> matrix(*rows, vector<int>(*columns, 0));
    populateMatrix(matrix);

}
