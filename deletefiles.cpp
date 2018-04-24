#include "functions.h"

void deleteFiles(int iterations, string* file_names) {

    for(int i = 0; i < iterations; i++) remove(file_names[i].c_str());

}