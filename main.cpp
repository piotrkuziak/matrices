#include "functions.h"

using namespace std;

int main() {

    int rows = 3, columns = 4, **matrix_passed;

//    if(getData(&rows, &columns) != OK) {
//        cout << endl << MSG_ERR_WRONG_DATA << endl;
//        return ERR_WRONG_DATA;
//    }

    switch(createMatrix(&rows, &columns, &matrix_passed)) {
        case ERR_WRONG_DATA:
            cout << endl << MSG_ERR_WRONG_DATA << endl;
            break;
        case ERR_MEMORY_ALLOC_FAIL:
            #ifdef DEBUG
                cout << endl << MSG_ERR_MEMORY_ALLOC_FAIL << endl;
            #endif
            break;
        default:
            break;
    }

    populateMatrix(&rows, &columns, &matrix_passed);

//    for(int i = 0; i < rows; i++){
//        cout << "[";
//        for(int j = 0; j < columns; j++) {
//            cout << " " << **matrix_passed << " ";
//            *matrix_passed += 1;
//        }
//        cout << "]" << endl;
//        matrix_passed += 1;
//    }

    return OK;
}