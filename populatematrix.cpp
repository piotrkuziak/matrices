#include "functions.h"

int populateMatrix(int *rows, int *columns, int ***matrix_passed) {

    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(1.00, 100.00);

    for(int i = 0; i < *rows; i++){
        for(int j = 0; j < *columns; j++) {
            ***matrix_passed = dist(mt);
            **matrix_passed += 1;
        }
        *matrix_passed += 1;
    }

    cout << ***matrix_passed;

//    *matrix_passed += 1; rows
//    **matrix_passed += 1; columns

//    for(int i = 0; i < *rows; i++){
//        cout << "[";
//        for(int j = 0; j < *columns; j++) {
//            cout << " " << ***matrix_passed << " ";
//            **matrix_passed += 1;
//        }
//        cout << "]" << endl;
//        *matrix_passed += 1;
//    }

    return OK;

}