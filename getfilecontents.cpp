#include "functions.h"

int getFileContents(string* file_names, int*** matrix_one_pointer, int*** matrix_two_pointer) {

    int rows = 0, columns = 0, **matrix;

    for(int i = 0; i < 2 ; i++){
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

        if(i == 0) *matrix_one_pointer = matrix;
        if(i == 1) *matrix_two_pointer = matrix;

        file.close();

    }

    return OK;

}