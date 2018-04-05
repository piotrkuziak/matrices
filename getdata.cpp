#include "functions.h"

tuple<int, int, string> getData() {

    int rows = 4, columns = 5;
    int *rows_pointer = &rows, *columns_pointer = &columns;

    string fileName = "Plik";
    string *fileName_pointer = &fileName;

    try {
        return make_tuple(*rows_pointer, *columns_pointer, *fileName_pointer);
    } catch (int e) {
        cout << "Exception number " << e;
    }

}