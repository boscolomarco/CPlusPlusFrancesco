#include "EventReadFromFile.h"

#include "Event.h"

#include <iostream>
#include <fstream>
#include <string>

//Read data from the txt file:
EventReadFromFile::EventReadFromFile(const std::string &name){
    file = new std::ifstream(name.c_str());

}

EventReadFromFile::~EventReadFromFile(){
    delete file;
}

const Event *EventReadFromFile::get(){
    return readFile();
}

const Event *EventReadFromFile::readFile(){

    //Puntatore ad Event
    Event *ev;
    int Id;
    float x, y, z;
    int numberParticle;

    //Legge il file 
        if(*file >> Id >> x >> y >> z){
        ev = new Event(Id, x, y, z);
    }
    else{
        return nullptr;
    }
    //Leggo numero di particelle da file 

    *file >> numberParticle;

    //Leggo carica e momenti da file
    for(int i = 0; i < numberParticle; ++i){

        int charge;
        float p_x, p_y, p_z;

        *file >> charge >> p_x >> p_y >> p_z;
        ev ->add(charge, p_x, p_y, p_z);
    }

    return ev;
}