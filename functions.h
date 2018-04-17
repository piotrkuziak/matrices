#ifndef MATRICES_FUNCTIONS_H
#define MATRICES_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "errors.h"
#include "messages.h"

using namespace std;

int getData(int *rows, int *columns, string *file_name);
int createMatrix(int rows, int columns, int*** matrix_pointer);
int populateMatrix(int rows, int columns, int** matrix_pointer);
void showMatrix(int rows, int columns, int** matrix_pointer);
int createFile(string file_name);
int populateFile(int** matrix, string file_name);

#endif //MATRICES_FUNCTIONS_H
