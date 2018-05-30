#include "functions.h"

using namespace std;

int main() {

    int rows = 0, columns = 0, iterations = 0,
            **matrix_pointer = NULL, **matrix_sizes = NULL, ***matrix_array = NULL;
    string file_name, file_names[2];
    bool identity_matrix = false;

    allocateMemory(matrix_sizes, 3, 2);
    allocateMemory(matrix_array, 3);

    for(int i = 0; i < 2; i++) {

        iterations++;

        if(getData(&rows, &columns, &file_name, &identity_matrix) != OK) {
            cout << endl << MSG_ERR_WRONG_DATA << endl;
            deleteFiles(iterations, file_names);
            return ERR_WRONG_DATA;
        }

        matrix_sizes[i][0] = rows;
        matrix_sizes[i][1] = columns;
        file_names[i] = file_name;

        switch(allocateMemory(matrix_pointer, rows, columns)) {
            case ERR_WRONG_DATA:
                cout << endl << MSG_ERR_WRONG_DATA << endl;
                deleteFiles(iterations, file_names);
                return ERR_WRONG_DATA;
            case ERR_MEMORY_ALLOC_FAIL:
                #ifdef DEBUG
                    cout << endl << MSG_ERR_MEMORY_ALLOC_FAIL << endl;
                #endif
                deleteFiles(iterations, file_names);
                return ERR_MEMORY_ALLOC_FAIL;
            default:
                break;
        }

        if(populateMatrix(rows, columns, matrix_pointer, identity_matrix) != OK) {
            #ifdef DEBUG
                cout << endl << MSG_ERR_MEMORY_ALLOC_FAIL << endl;
            #endif
            deleteFiles(iterations, file_names);
            return ERR_MEMORY_ALLOC_FAIL;
        }

        if(i > 0) {
            if(checkSizes(matrix_sizes[0][1], matrix_sizes[1][0]) != OK) {
                cout << endl << MSG_ERR_MATRICES_WRONG_SIZE << endl;
                deleteFiles(iterations, file_names);
                return ERR_MATRICES_WRONG_SIZE;
            }
        }

        switch(createFile(file_name)) {
            case ERR_WRONG_DATA:
                cout << endl << MSG_ERR_WRONG_DATA << endl;
                deleteFiles(iterations, file_names);
                return ERR_WRONG_DATA;
            case ERR_FILE_EXISTS:
                cout << endl << MSG_ERR_FILE_EXISTS << endl;
                deleteFiles(iterations, file_names);
                return ERR_FILE_EXISTS;
            case ERR_FILE_CREATION_FAIL:
                cout << endl << MSG_ERR_FILE_CREATION_FAIL << endl;
                deleteFiles(iterations, file_names);
                return ERR_FILE_CREATION_FAIL;
            default:
                break;
        }

        if(populateFile(rows, columns, matrix_pointer, file_name) != OK) {
            cout << endl << MSG_ERR_FILE_POPULATION_FAIL << endl;
            deleteFiles(iterations, file_names);
            return ERR_FILE_POPULATION_FAIL;
        }

    } // FOR

    // CLEAR MEMORY

    switch(getFileContents(file_names, matrix_array)) {
        case ERR_FILE_DOESNT_EXIST:
            cout << endl << MSG_ERR_FILE_DOESNT_EXIST << endl;
            deleteFiles(iterations, file_names);
            return ERR_FILE_DOESNT_EXIST;
        case ERR_WRONG_DATA:
            cout << endl << MSG_ERR_WRONG_DATA << endl;
            deleteFiles(iterations, file_names);
            return ERR_WRONG_DATA;
        default:
            break;
    }

    switch(multiplyMatrices(matrix_sizes, matrix_array)) {
        case ERR_MATRICES_WRONG_SIZE:
            cout << endl << MSG_ERR_MATRICES_WRONG_SIZE << endl;
            deleteFiles(iterations, file_names);
            return ERR_MATRICES_WRONG_SIZE;
        case ERR_WRONG_DATA:
            cout << endl << MSG_ERR_WRONG_DATA << endl;
            deleteFiles(iterations, file_names);
            return ERR_WRONG_DATA;
        default:
            break;
    }

    cout << endl;

    for(int i = 0; i < 3; i++) {
        showMatrix(matrix_sizes[i][0], matrix_sizes[i][1], matrix_array[i]);
        cout << endl;
    }

    // CLEAR MEMORY

//    if(multiplyMatrices(amount_of_matrices, matrix_sizes, matrix_array) != OK) {
//        cout << endl << MSG_ERR_MATRICES_WRONG_SIZE << endl;
//        deleteFiles(iterations, file_names);
//        return ERR_MATRICES_WRONG_SIZE;
//    }

//    if(populateFile(matrix_sizes[0], matrix_sizes[3], matrix_multiplied, new_file_name) != OK) {
//        cout << endl << MSG_ERR_FILE_POPULATION_FAIL << endl;
//        return ERR_FILE_POPULATION_FAIL;
//    }

    return OK;
}