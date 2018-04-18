#include "functions.h"

using namespace std;

int main() {

    int rows = 0, columns = 0, **matrix_pointer, **matrix_array;
    string file_name, file_names[2];

    for(int i = 0; i < 2; i++) {

        if(getData(&rows, &columns, &file_name) != OK) {
            cout << endl << MSG_ERR_WRONG_DATA << endl;
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

        showMatrix(rows, columns, matrix_pointer);

    }

    getFileContents(file_names, &matrix_array);

    cout << endl << "MAIN" << endl;
    cout << matrix_array[0] << endl;
    cout << matrix_array[1] << endl;

    return OK;
}