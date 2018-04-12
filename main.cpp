#include "functions.h"

using namespace std;

int main() {

    int rows = 0, columns = 0, **matrix;

    if(getData(&rows, &columns) != OK) {
        cout << endl << MSG_ERR_WRONG_DATA << endl;
        return ERR_WRONG_DATA;
    }

    switch(createMatrix(&rows, &columns, &matrix)) {
        case ERR_WRONG_DATA:
            cout << endl << MSG_ERR_WRONG_DATA << endl;
            break;
        case ERR_MEMORY_ALLOC_FAIL:
            #ifdef DEBUG
                cout << endl << MSG_ERR_MEMORY_ALLOC_FAIL << endl;
            #endif
            break;
        default:
            break;
    }

    return OK;
}