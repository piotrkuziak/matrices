#ifndef MATRICES_FUNCTIONS_H
#define MATRICES_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "errors.h"
#include "messages.h"

using namespace std;

const int LIMIT = 5;

int getAmount(int *amount);
int getData(int *rows, int *columns, string *file_name);
int createMatrix(int rows, int columns, int*** matrix_pointer);
int populateMatrix(int rows, int columns, int** matrix_pointer);
int createFile(string file_name);
int populateFile(int rows, int columns, int** matrix, string file_name);
int getFileContents(int amount_of_matrices, string* file_names, int*** matrix_array);
int multiplyMatrices(int amount_of_matrices, int** matrix_sizes, int*** matrix_array);
void showMatrix(int rows, int columns, int** matrix_pointer);
void clearMemory(int rows, int** matrix);
void deleteFiles(int iterations, string* file_names);

#endif //MATRICES_FUNCTIONS_H
