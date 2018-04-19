#include "functions.h"

int getAmount(int *amount) {

    cout << MSG_GET_AMOUNT;
    cin >> *amount;

    if(*amount == NULL) return ERR_WRONG_DATA;
    if(*amount > LIMIT) return ERR_LIMIT_SURPASSED;

    return OK;

}
