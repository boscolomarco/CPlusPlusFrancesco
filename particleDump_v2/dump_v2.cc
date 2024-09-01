#include <iostream>
#include <fstream>

#include "Struct.h"

void dump(const Event &ev){

    std::cout << ev.evId << std::endl;
    std::cout << ev.x << " " << ev.y << " " << ev.z << std::endl;

    std::cout << ev.nPar << std::endl;

    for(int i = 0; i < ev.nPar; ++i){

        Particle *part = ev.p[i];
        std::cout << part -> charge << " " << part -> p_x << " " << part -> p_y << " " << part -> p_z << std::endl;
    }
}