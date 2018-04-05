#include "functions.h"

void showMatrix(vector<vector<int>> matrix) {

    for(int i = 0; i < matrix.size(); i++){
        cout << "[";
        for(int j = 0; j < matrix[0].size(); j++){
            cout << " " << matrix[i][j] << " ";
        }
        cout << "]" << endl;
    }

}