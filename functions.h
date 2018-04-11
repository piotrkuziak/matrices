#include <iostream>
#include <vector>
#include <random>
#include <fstream>

#include "errors.h"
#include "messages.h"

using namespace std;

#ifndef MATRICES_FUNCTIONS_H
#define MATRICES_FUNCTIONS_H

int getData(int *rows, int *columns);
int createMatrix(int *rows, int *columns);
int populateMatrix();
//void showMatrix(vector<vector<int>> matrix);
//tuple<ofstream, int> createFile(string *fileName);
//int populateFile(vector<vector<int>> matrix, string *fileName);

#endif //MATRICES_FUNCTIONS_H
