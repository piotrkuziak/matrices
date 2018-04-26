#include "functions.h"

// ONE DIMENSION STRING
int allocateMemory(string*& array, int first) {

    if(first == NULL)
        return ERR_WRONG_DATA;

    array = new (nothrow) string [first];

    if(array == nullptr)
        return ERR_MEMORY_ALLOC_FAIL;

    return OK;

}

// ONE DIMENSION INT
int allocateMemory(int*& array, int first) {

    if(first == NULL)
        return ERR_WRONG_DATA;

    array = new (nothrow) int [first];

    if(array == nullptr)
        return ERR_MEMORY_ALLOC_FAIL;

    return OK;

}

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
int allocateMemory(int***& array, int first, int second, int third) {

    if(first == NULL || second == NULL || third == NULL)
        return ERR_WRONG_DATA;

    array = new (nothrow) int** [first];

    for(int i = 0; i < first; i++)
        array[i] = new (nothrow) int* [second];

    for(int i = 0; i < first; i++) {
        for(int j = 0; j < second; j++)
            array[i][j] = new (nothrow) int [third];
    }

    if(array == nullptr)
        return ERR_MEMORY_ALLOC_FAIL;

    for(int i = 0; i < first; i++) {
        if(array[i] == nullptr)
            return ERR_MEMORY_ALLOC_FAIL;
    }

    for(int i = 0; i < first; i++) {
        for(int j = 0; j < second; j++) {
            if(array[i][j] == nullptr)
                return ERR_MEMORY_ALLOC_FAIL;
        }
    }

    return OK;

}
