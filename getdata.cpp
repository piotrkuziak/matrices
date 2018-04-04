#include "functions.h"

void getData() {

    int rows = 0, columns = 0;
    int *rows_pointer = &rows, *columns_pointer = &columns;

    string fileName;
    string *fileName_pointer = &fileName;

    cout << "Podaj liczbę wierszy: ";
    cin >> rows;

    //cout << "Podaj liczbę kolumn: ";
    //cin >> columns;

    //cout << "Podaj nazwę pliku: ";
    //cin >> fileName;

    createMatrix(rows_pointer, columns_pointer);

}