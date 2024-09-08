#include <iostream>
#include <vector>
#include <sstream>

#include "EventSource.h"
#include "EventReadFromFile.h"
#include "EventSim.h"
#include "AnalysisSteering.h"
#include "EventDump.h"
#include "ParticleMass.h"
#include "Event.h"

int main(int argc, char *argv[]){

    //Creo un interfaccia astratta di es 
    EventSource *es;
    const std::string type = argv[1];

    if(type == "input"){
        const std::string name = argv[2];
        es = new EventReadFromFile(name);
    }
    else if (type =="sim"){
        const std::string nevt = argv[2];
        const std::string seed = ( argc > 3 ? argv[3] : "1" );
        std::stringstream sstr;
        unsigned int n;
        sstr.str( nevt );
        sstr >> n;
        sstr.clear();
        unsigned int s;
        sstr.str( seed );
        sstr >> s;
        es = new EventSim( n, s );
    }
    else {
        std::cout << "Invalid Keyword" << std::endl;
        return 0;
    }

    std::vector<AnalysisSteering*> aList;

    //creo un oggetto su cui effetturare il dump e immagazzinare la lista di analizzatori
    aList.push_back(new EventDump);

    //ccreo un oggetto su cui effettuare l'analisi di massa media e RMS
    aList.push_back(new ParticleMass);

    for(auto as : aList){
        as ->beginJob();
    }

    const Event *ev;
    while((ev = es->get()) != nullptr){
        for(auto as : aList){
            as ->process(*ev);
        }
        delete ev;
    }

    for (auto as : aList){
        as ->endJob();

        delete as;
    }

    delete es;

    return 0;
}