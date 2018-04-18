#include "functions.h"

int getFileContents(string* file_names, int*** matrix_array) {

    int rows = 0, columns = 0, **matrices = new int* [2];

    cout << endl << "GETFILECONTENTS" << endl;

    ifstream file (file_names[0]);
    ifstream file2 (file_names[1]);

    file >> rows >> columns;
    int matrix[rows][columns];
    cout << "ROWS: " << rows << endl;
    cout << "COLUMNS: " << columns << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            file >> matrix[i][j];
        }
    }
    for(int i = 0; i < rows; i++) {
        cout << "[";
        for(int j = 0; j < columns; j++) {
            cout << " " << matrix[i][j] << " ";
        }
        cout << "]" << endl;
    }

    file2 >> rows >> columns;
    int matrix2[rows][columns];
    cout << "ROWS: " << rows << endl;
    cout << "COLUMNS: " << columns << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            file2 >> matrix2[i][j];
        }
    }
    for(int i = 0; i < rows; i++) {
        cout << "[";
        for(int j = 0; j < columns; j++) {
            cout << " " << matrix2[i][j] << " ";
        }
        cout << "]" << endl;
    }

    matrices[0] = *matrix;
    matrices[1] = *matrix2;

    *matrix_array = matrices;

    return OK;

}