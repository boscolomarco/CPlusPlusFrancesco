#include <iostream>

#include "Struct.h"

void clear(const Event *ev){

    for(int i = 0; i < ev -> nPar; ++i){
        delete [] ev -> p[i];
    }
    
    delete [] ev -> p;
    delete ev;


}