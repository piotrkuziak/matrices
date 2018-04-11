#include "functions.h"

int createMatrix(int *rows, int *columns) {

    if(*rows == nullptr || *columns == nullptr) {
        cout << endl << MSG_ERR_WRONG_DATA << endl;
        return ERR_WRONG_DATA;
    }

    int *matrix;
    matrix = new (nothrow) int [*rows];

    if(matrix == nullptr) {
        cout << endl << MSG_ERR_MEMORY_ALLOC_FAIL << endl;
        return ERR_MEMORY_ALLOC_FAIL;
    }

    return OK;

}
