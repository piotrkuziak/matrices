#include "functions.h"

void populateMatrix(vector<vector<int>> matrix) {

    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(1.00, 100.00);

    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            matrix[i][j] = dist(mt);
        }
    }

    showMatrix(matrix);

}