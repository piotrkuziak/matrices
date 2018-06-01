#include "functions.h"

// TWO DIMENSIONS INT
int deallocateMemory(int**& array, int first) {

    if(first == NULL)
        return ERR_WRONG_DATA;

    for(int i = 0; i < first; i++)
        delete [] array[i];

    delete [] array;

    return OK;

}

// THREE DIMENSIONS INT
int deallocateMemory(int***& array, int first) {

    if(first == NULL)
        return ERR_WRONG_DATA;

    for(int i = 0; i < first; i++)
        delete [] array[i];

    delete [] array;

    return OK;

}