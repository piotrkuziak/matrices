#include "functions.h"

// TWO DIMENSIONS INT
int deallocateMemory(int**& array, int first, int second) {

    if(first == NULL || second == NULL)
        return ERR_WRONG_DATA;

    for(int i = 0; i < first; i++)
        delete [] array[first];

    delete [] array;

    return OK;

}