#include "functions.h"
#include <random>

void populateMatrix(vector<int> matrix) {

    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(1.00, 100.00);

    for (int &i : matrix) i = dist(mt);
    for (int i : matrix) cout << " " << i << " ";
}