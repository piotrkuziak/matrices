#include "functions.h"

tuple<ofstream, int> createFile(string *fileName) {

    int status = 1;

    ofstream file;
    //file.open(*fileName);

    if(file.fail()) status = ERR_FILE_CREATION_FAIL;

    //return make_tuple(file, status);

}