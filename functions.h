#ifndef MATRICES_FUNCTIONS_H
#define MATRICES_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <regex>

#include "errors.h"
#include "messages.h"

using namespace std;

int getData(int *rows, int *columns, string *file_name, bool *identity_matrix);
int populateMatrix(int rows, int columns, int** matrix_pointer, bool identity_matrix);
int createFile(string file_name);
int populateFile(int rows, int columns, int** matrix, string file_name);
int getFileContents(string* file_names, int*** matrix_array);
int multiplyMatrices(int** matrix_sizes, int*** matrix_array);
void showMatrix(int rows, int columns, int** matrix_pointer);
void deleteFiles(int iterations, string* file_names);

int allocateMemory(int**& array, int first, int second);
int allocateMemory(int***& array, int first);

int deallocateMemory(int**& array, int first);
int deallocateMemory(int***& array, int first);

int is_digit(string data);
int checkSizes(int matrix_one_columns, int matrix_two_rows);

#endif //MATRICES_FUNCTIONS_H
