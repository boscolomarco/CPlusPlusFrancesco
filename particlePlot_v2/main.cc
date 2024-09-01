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
#include "SourceFactory.h"
#include "AnalysisInfo.h"

int main(int argc, char *argv[]){

    //raccoglie i parametri iniziali in input dal terminale
    AnalysisInfo *info = new AnalysisInfo(argc, argv);

    //Elabora i parametri iniziali e crea il costruttore in base all'input
    EventSource *es = SourceFactory::create(info);

    
    std::vector<AnalysisSteering*> aList;

    //Create a object to dump event and store into list of analyzers:
    aList.push_back(new EventDump);

    //create object to compute mean and rms and stores into list of analyzers:
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