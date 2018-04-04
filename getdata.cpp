#include "functions.h"

void getData() {

    int rows = 3, columns = 3;
    int *rows_pointer = &rows, *columns_pointer = &columns;

    string fileName;
    string *fileName_pointer = &fileName;

    createMatrix(rows_pointer, columns_pointer);

}