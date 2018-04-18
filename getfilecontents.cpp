#include "functions.h"

int getFileContents(string* file_names, int*** matrix_one_pointer, int*** matrix_two_pointer) {

    int rows = 0, columns = 0;
    string file_name_one = file_names[0], file_name_two = file_names[1];

    ifstream file (file_name_one);
    ifstream file2 (file_name_two);

    file >> rows >> columns;
    int **matrix = new int* [rows];
    for(int i = 0; i < rows; i++) matrix[i] = new int [columns];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            file >> matrix[i][j];
        }
    }

    file2 >> rows >> columns;
    int **matrix2 = new int* [rows];
    for(int i = 0; i < rows; i++) matrix2[i] = new int [columns];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            file2 >> matrix2[i][j];
        }
    }

    *matrix_one_pointer = matrix;
    *matrix_two_pointer = matrix2;

    return OK;

}