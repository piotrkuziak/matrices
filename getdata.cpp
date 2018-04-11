#include "functions.h"

tuple<int, int, string, int> getData() {

    int rows, columns, status = 1;
    int *rows_pointer = &rows, *columns_pointer = &columns;

    string fileName = "Plik";
    string *fileName_pointer = &fileName;

    cout << "Wiersze: ";
    cin >> rows;

    cout << "Kolumny: ";
    cin >> columns;

    if(cin.fail()) status = ERR_WRONG_DATA;

    return make_tuple(*rows_pointer, *columns_pointer, *fileName_pointer, status);

}