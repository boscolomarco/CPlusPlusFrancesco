#include "EventDump.h"
#include "Event.h"
#include <iostream>

EventDump::EventDump(){

}

EventDump::~EventDump(){

}

//Function to call when execution starts/ends
void EventDump::beginJob(){
    return;
}

void EventDump::endJob(){
    return;
}

//Function to be called for each event
void EventDump::process(const Event &ev){

    std::cout << ev.eventNumber() << std::endl;
    std::cout << ev.getX() << " " << ev.getY() << " " << ev.getZ() << std::endl;

    std::cout << ev.nParticles() << std::endl;


    for(int i = 0; i < ev.nParticles(); ++i){
        const Event::Particle *part = ev.particle(i);

        std::cout << part ->charge << " " << part ->p_x << " " << part ->p_y << " " << part ->p_z << std::endl;
    }
}

