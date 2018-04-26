#include "functions.h"

int getData(int *rows, int *columns, string *file_name, bool *identity_matrix) {

    char identity_matrix_condition;

    cout << MSG_IDENTITY_MATRIX;
    cin >> identity_matrix_condition;

    switch(identity_matrix_condition) {
        case 't':
        case 'T':
            cout << MSG_GET_IDENTITY_MATRIX_SIZE;
            cin >> *rows;
            *columns = *rows;
            *identity_matrix = true;
            break;
        case 'n':
        case 'N':
            cout << MSG_GET_ROWS;
            cin >> *rows;
            cout << MSG_GET_COLUMNS;
            cin >> *columns;
            break;
        default:
            return ERR_WRONG_DATA;
    }

    if(cin.fail() || *rows <= 0 || *columns <= 0) return ERR_WRONG_DATA;

    cout << MSG_GET_FILE_NAME;
    cin >> *file_name;

    if(*file_name == "") {
        return ERR_WRONG_DATA;
    }

    return OK;

}