#include "functions.h"

vector<vector<int>> createMatrix(int *rows, int *columns) {

    vector<vector<int>> matrix(*rows, vector<int>(*columns, 0));

    return matrix;

}
