#include "functions.h"

using namespace std;

int main() {
    auto a = getData();
    //populateMatrix(createMatrix(&get<0>(a), &get<1>(a)));
    createFile(&get<2>(a));
    return 0;
}