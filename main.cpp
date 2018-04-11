#include "functions.h"

using namespace std;

int main() {

    int rows = 0, columns = 0;

    if(getData(&rows, &columns) != OK) {
        cout << endl << MSG_ERR_WRONG_DATA << endl;
        return ERR_WRONG_DATA;
    }

    createMatrix(&rows, &columns);

    return OK;
}