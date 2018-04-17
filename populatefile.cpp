#include "functions.h"

int populateFile(int rows, int columns, int** matrix, string file_name) {

    ofstream file;

    file.open(file_name);
    file << rows << " " << columns << endl;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            file << matrix[i][j] << " ";
        }
        file << endl;
    }

    file.close();

    if(!file) {
        return ERR_FILE_POPULATION_FAIL;
    }

    return OK;

}