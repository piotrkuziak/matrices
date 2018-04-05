#include "functions.h"

using namespace std;

int main() {

    auto a = getData();

    if(get<3>(a) != OK) {
        cout << endl << MSG_ERR << endl;
        return 0;
    }

    populateMatrix(createMatrix(&get<0>(a), &get<1>(a)));
    //createFile(&get<2>(a));
    return 0;
}