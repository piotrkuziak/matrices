#include "functions.h"

using namespace std;

int main() {

    int rows = 0, columns = 0, **matrix_pointer, **matrix_one_pointer, **matrix_two_pointer, **matrix_multiplied, matrix_sizes[4];
    string file_name, file_names[2], new_file_name;

    for(int i = 0; i < 2; i++) {

        if(getData(&rows, &columns, &file_name) != OK) {
            cout << endl << MSG_ERR_WRONG_DATA << endl;
            return ERR_WRONG_DATA;
        }

        if(i == 0) {
            matrix_sizes[0] = rows;
            matrix_sizes[1] = columns;
        }

        if(i == 1) {
            matrix_sizes[2] = rows;
            matrix_sizes[3] = columns;
        }

        switch(createMatrix(rows, columns, &matrix_pointer)) {
            case ERR_WRONG_DATA:
                cout << endl << MSG_ERR_WRONG_DATA << endl;
                return ERR_WRONG_DATA;
            case ERR_MEMORY_ALLOC_FAIL:
                #ifdef DEBUG
                    cout << endl << MSG_ERR_MEMORY_ALLOC_FAIL << endl;
                #endif
                return ERR_MEMORY_ALLOC_FAIL;
            default:
                break;
        }

        if(populateMatrix(rows, columns, matrix_pointer) != OK) {
            #ifdef DEBUG
                cout << endl << MSG_ERR_MEMORY_ALLOC_FAIL << endl;
            #endif
            return ERR_MEMORY_ALLOC_FAIL;
        }

        switch(createFile(file_name)) {
            case ERR_WRONG_DATA:
                cout << endl << MSG_ERR_WRONG_DATA << endl;
                return ERR_WRONG_DATA;
            case ERR_FILE_EXISTS:
                cout << endl << MSG_ERR_FILE_EXISTS << endl;
                return ERR_FILE_EXISTS;
            case ERR_FILE_CREATION_FAIL:
                cout << endl << MSG_ERR_FILE_CREATION_FAIL << endl;
                return ERR_FILE_CREATION_FAIL;
            default:
                break;
        }

        if(populateFile(rows, columns, matrix_pointer, file_name) != OK) {
            cout << endl << MSG_ERR_FILE_POPULATION_FAIL << endl;
            return ERR_FILE_POPULATION_FAIL;
        }

        clearMemory(rows, matrix_pointer);

        file_names[i] = file_name;

    }

    if(getFileContents(file_names, &matrix_one_pointer, &matrix_two_pointer) != OK) {
        #ifdef DEBUG
            cout << endl << MSG_ERR_FILE_DOESNT_EXIST << endl;
        #endif
        return ERR_FILE_DOESNT_EXIST;
    }

    if(multiplyMatrices(matrix_sizes, matrix_one_pointer, matrix_two_pointer, &matrix_multiplied) != OK) {
        cout << endl << MSG_ERR_MATRICES_WRONG_SIZE << endl;
        return ERR_MATRICES_WRONG_SIZE;
    } else {
        cout << MSG_MULTIPLYING_MATRICE << endl;
    }

    new_file_name = file_names[0] + "_" + file_names[1];

    switch(createFile(new_file_name)) {
        case ERR_WRONG_DATA:
            cout << endl << MSG_ERR_WRONG_DATA << endl;
            return ERR_WRONG_DATA;
        case ERR_FILE_EXISTS:
            cout << endl << MSG_ERR_FILE_EXISTS << endl;
            return ERR_FILE_EXISTS;
        case ERR_FILE_CREATION_FAIL:
            cout << endl << MSG_ERR_FILE_CREATION_FAIL << endl;
            return ERR_FILE_CREATION_FAIL;
        default:
            break;
    }

    if(populateFile(matrix_sizes[0], matrix_sizes[3], matrix_multiplied, new_file_name) != OK) {
        cout << endl << MSG_ERR_FILE_POPULATION_FAIL << endl;
        return ERR_FILE_POPULATION_FAIL;
    } else {
        cout << MSG_SAVING_MULTIPLIED_MATRICE << endl;
    }

    showMatrix(matrix_sizes[0], matrix_sizes[3], matrix_multiplied);

    clearMemory(matrix_sizes[0], matrix_multiplied);

    cout << endl << MSG_SUCCESS << endl;

    return OK;
}