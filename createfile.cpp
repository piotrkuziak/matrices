#include "functions.h"

int createFile(string file_name) {

    if(file_name == "") {
        return ERR_WRONG_DATA;
    }

//    if(ifstream(file_name)) {
//        return ERR_FILE_EXISTS;
//    }

    ofstream file (file_name);
    file.close();

    if(!file) {
        return ERR_FILE_CREATION_FAIL;
    }

    return OK;

}