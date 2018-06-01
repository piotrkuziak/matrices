#include "functions.h"

// TWO DIMENSIONS INT
int allocateMemory(int**& array, int first, int second) {

    if(first == NULL || second == NULL)
        return ERR_WRONG_DATA;

    array = new (nothrow) int* [first];

    for(int i = 0; i < first; i++)
        array[i] = new (nothrow) int [second];

    if(array == nullptr)
        return ERR_MEMORY_ALLOC_FAIL;

    for(int i = 0; i < first; i++) {
        if(array[i] == nullptr)
            return ERR_MEMORY_ALLOC_FAIL;
    }

    return OK;

}

// THREE DIMENTIONS INT
int allocateMemory(int***& array, int first) {

    if(first == NULL)
        return ERR_WRONG_DATA;

    array = new (nothrow) int** [first];

    if(array == nullptr)
        return ERR_MEMORY_ALLOC_FAIL;

    return OK;

}
