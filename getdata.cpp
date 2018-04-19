#include "functions.h"

int getData(int *rows, int *columns, string *file_name) {

    cout << MSG_GET_ROWS;
    cin >> *rows;

    cout << MSG_GET_COLUMNS;
    cin >> *columns;

    if(cin.fail() || *rows <= 0 || *columns <= 0) return ERR_WRONG_DATA;

    cout << MSG_GET_FILE_NAME;
    cin >> *file_name;

    if(*file_name == "") {
        return ERR_WRONG_DATA;
    }

    return OK;

}