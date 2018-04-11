#include "functions.h"

using namespace std;

int main() {

    int rows = 0, columns = 0;

    if(getData(&rows, &columns) != OK) {
        cout << endl << MSG_ERR_WRONG_DATA << endl;
        return ERR_WRONG_DATA;
    }

    switch(createMatrix(&rows, &columns)) {
        case ERR_WRONG_DATA:
            cout << endl << MSG_ERR_WRONG_DATA << endl;
            break;
        case ERR_MEMORY_ALLOC_FAIL:
            cout << endl << MSG_ERR_MEMORY_ALLOC_FAIL << endl;
            break;
    }

    return OK;
}