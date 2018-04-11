#include <iostream>
#include <vector>
#include <random>
#include <tuple>
#include <stdexcept>
#include <fstream>

#include "errors.h"
#include "messages.h"

using namespace std;

#ifndef MATRICES_FUNCTIONS_H
#define MATRICES_FUNCTIONS_H

tuple<int, int, string, int> getData();
vector<vector<int>> createMatrix(int *rows, int *columns);
void populateMatrix(vector<vector<int>> matrix);
void showMatrix(vector<vector<int>> matrix);
tuple<ofstream, int> createFile(string *fileName);
int populateFile(vector<vector<int>> matrix, string *fileName);

#endif //MATRICES_FUNCTIONS_H
