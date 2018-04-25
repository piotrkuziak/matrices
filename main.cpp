#include "functions.h"

using namespace std;

int main() {

    int amount_of_matrices = 3,
            rows = 0,
            columns = 0,
            iterations = 0,
            **matrix_pointer,
            ***matrix_array,
            **matrix_sizes;

    string file_name, *file_names;

//    switch(getAmount(&amount_of_matrices)) {
//        case ERR_WRONG_DATA:
//            cout << endl << MSG_ERR_WRONG_DATA << endl;
//            return ERR_WRONG_DATA;
//        case ERR_LIMIT_SURPASSED:
//            cout << endl << MSG_ERR_LIMIT_SURPASSED << LIMIT << endl;
//            return ERR_LIMIT_SURPASSED;
//        default:
//            break;
//    }

    file_names = new string [amount_of_matrices];

    matrix_array = new int** [amount_of_matrices];

    matrix_sizes = new int* [amount_of_matrices];
    for(int i = 0; i < amount_of_matrices; i++) matrix_sizes[i] = new int [2];

    for(int i = 0; i < amount_of_matrices; i++) {

        iterations++;

        if(getData(&rows, &columns, &file_name) != OK) {
            cout << endl << MSG_ERR_WRONG_DATA << endl;
            deleteFiles(iterations, file_names);
            return ERR_WRONG_DATA;
        }

        switch(createMatrix(rows, columns, &matrix_pointer)) {
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

        if(populateMatrix(rows, columns, matrix_pointer) != OK) {
            #ifdef DEBUG
                cout << endl << MSG_ERR_MEMORY_ALLOC_FAIL << endl;
            #endif
            deleteFiles(iterations, file_names);
            return ERR_MEMORY_ALLOC_FAIL;
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

        file_names[i] = file_name;
        matrix_sizes[i][0] = rows;
        matrix_sizes[i][1] = columns;

    }

//    if(getFileContents(amount_of_matrices, file_names, matrix_array) != OK) {
//        #ifdef DEBUG
//            cout << endl << MSG_ERR_FILE_DOESNT_EXIST << endl;
//        #endif
//        deleteFiles(iterations, file_names);
//        return ERR_FILE_DOESNT_EXIST;
//    }

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