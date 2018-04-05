#include "functions.h"
#include <typeinfo>

int createFile(string *fileName) {

    ofstream plik;
    cout << "Typ: " << typeid(plik).name() << endl;

}