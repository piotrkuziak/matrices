#include "functions.h"

using namespace std;

int main() {

    //cout << "\n\033[31mtext\033[0m";

    int amount_of_matrices = 5, rows = 2, columns = 2, **matrix_pointer, ***matrix_array;
//    int **matrix_pointer, **matrix_one_pointer, **matrix_two_pointer, **matrix_multiplied, matrix_sizes[4];
    string file_name, *file_names;

//    if(getAmount(&amount_of_matrices) != OK) {
//        cout << endl << MSG_ERR_WRONG_DATA << endl;
//        return ERR_WRONG_DATA;
//    }

    file_names = new string [amount_of_matrices];
    matrix_array = new int** [amount_of_matrices];

    for(int i = 0; i < amount_of_matrices; i++) {

        if(getData(&rows, &columns, &file_name) != OK) {
            cout << "\n\033[31m" << MSG_ERR_WRONG_DATA << "\033[0m\n";
            return ERR_WRONG_DATA;
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

        file_names[i] = file_name;

    }

//    cout << "Nazwy plików:";
//
//    for(int i = 0; i < amount_of_matrices; i++) {
//        cout << " " << file_names[i] << " ";
//    }

    getFileContents(amount_of_matrices, file_names, matrix_array);

//    if(getFileContents(file_names, &matrix_one_pointer, &matrix_two_pointer) != OK) {
//        #ifdef DEBUG
//            cout << endl << MSG_ERR_FILE_DOESNT_EXIST << endl;
//        #endif
//        return ERR_FILE_DOESNT_EXIST;
//    }

//    if(multiplyMatrices(matrix_sizes, matrix_one_pointer, matrix_two_pointer, &matrix_multiplied) != OK) {
//        cout << endl << MSG_ERR_MATRICES_WRONG_SIZE << endl;
//        return ERR_MATRICES_WRONG_SIZE;
//    } else {
//        cout << MSG_MULTIPLYING_MATRICE << endl;
//    }
//
//    new_file_name = file_names[0] + "_" + file_names[1];
//
//    switch(createFile(new_file_name)) {
//        case ERR_WRONG_DATA:
//            cout << endl << MSG_ERR_WRONG_DATA << endl;
//            return ERR_WRONG_DATA;
//        case ERR_FILE_EXISTS:
//            cout << endl << MSG_ERR_FILE_EXISTS << endl;
//            return ERR_FILE_EXISTS;
//        case ERR_FILE_CREATION_FAIL:
//            cout << endl << MSG_ERR_FILE_CREATION_FAIL << endl;
//            return ERR_FILE_CREATION_FAIL;
//        default:
//            break;
//    }
//
//    if(populateFile(matrix_sizes[0], matrix_sizes[3], matrix_multiplied, new_file_name) != OK) {
//        cout << endl << MSG_ERR_FILE_POPULATION_FAIL << endl;
//        return ERR_FILE_POPULATION_FAIL;
//    } else {
//        cout << MSG_SAVING_MULTIPLIED_MATRICE << endl;
//    }
//
//    showMatrix(matrix_sizes[0], matrix_sizes[3], matrix_multiplied);
//
//    clearMemory(matrix_sizes[0], matrix_multiplied);
//
//    cout << endl << MSG_SUCCESS << endl;

    return OK;
}