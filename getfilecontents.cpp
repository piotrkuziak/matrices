#include "functions.h"

int getFileContents(int amount_of_matrices, string* file_names, int*** matrix_array) {

    int rows = 0, columns = 0, **matrix;

    for(int i = 0; i < amount_of_matrices; i++){
        ifstream file (file_names[i]);

        if(!file) return ERR_FILE_DOESNT_EXIST;

        file >> rows >> columns;

        matrix = new int* [rows];
        for(int i = 0; i < rows; i++) matrix[i] = new int [columns];

        for(int j = 0; j < rows; j++) {
            for(int k = 0; k < columns; k++) {
                file >> matrix[j][k];
            }
        }

        matrix_array[i] = matrix;

        file.close();

    }

    return OK;

}