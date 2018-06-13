#include "functions.h"

int getFileContents(string* file_names, int*** matrix_array) {

    int rows = 0, columns = 0, **matrix;
    string value;

    for(int a = 0; a < 2; a++){
        ifstream file (file_names[a]);

        if(!file)
            return ERR_FILE_DOESNT_EXIST;

        file >> value;
        if(is_digit(value) == OK)
            rows = stoi(value);
        else
            return ERR_WRONG_DATA;

        file >> value;
        if(is_digit(value) == OK)
            columns = stoi(value);
        else
            return ERR_WRONG_DATA;

        allocateMemory(matrix, rows, columns);

        for(int j = 0; j < rows; j++) {
            for(int k = 0; k < columns; k++) {
                file >> value;
                if(is_digit(value) == OK)
                    matrix[j][k] = stoi(value);
                else
                    return ERR_WRONG_DATA;
            }
        }

        matrix_array[a] = matrix;

        file.close();

    }

    return OK;

}