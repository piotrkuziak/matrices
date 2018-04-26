#include "functions.h"

int populateMatrix(int rows, int columns, int** matrix_pointer) {

    char identity_matrix;

    if(matrix_pointer == nullptr) {
        return ERR_MEMORY_ALLOC_FAIL;
    }

    srand(time(NULL));

    cout << MSG_IDENTITY_MATRIX;
    cin >> identity_matrix;

    switch(identity_matrix) {
        case 't':
        case 'T':
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++) {
                    if(i == j)
                        matrix_pointer[i][j] = 1;
                    else
                        matrix_pointer[i][j] = 0;
                }
            }
            break;
        case 'n':
        case 'N':
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++) {
                    matrix_pointer[i][j] = (rand() % 100) + 1;
                }
            }
            break;
        default:
            return ERR_WRONG_DATA;
    }

    return OK;

}