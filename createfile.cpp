#include "functions.h"
#include <typeinfo>

void createFile(string *fileName) {

    ofstream plik;
    cout << "Typ: " << typeid(plik).name() << endl;

}