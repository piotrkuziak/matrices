#include "functions.h"

int is_digit(string data) {

    regex integer("(\\+|-)?[[:digit:]]+");

    if(regex_match(data, integer))
        return OK;
    else
        return ERR_WRONG_DATA;

}