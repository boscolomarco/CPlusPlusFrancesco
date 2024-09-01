#include <iostream>
#include <fstream>

#include "Event.h"

const Event *read(std::ifstream &file){

    Event *ev;
    int Id;
    float x, y, z;
    int numberParticle;


    if(file >> Id >> x >> y >> z){
        ev = new Event(Id, x, y, z);
    }
    else{
        return nullptr;
    }
    //Leggo numero di particelle da file 

    file >> numberParticle;

    //Leggo carica e momenti da file
    for(int i = 0; i < numberParticle; ++i){

        int charge;
        float p_x, p_y, p_z;

        file >> charge >> p_x >> p_y >> p_z;
        ev ->add(charge, p_x, p_y, p_z);
    }

    return ev;

}
