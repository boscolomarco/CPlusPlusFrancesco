#include <iostream>
#include <vector>
#include <sstream>

#include "AnalysisInfo.h"
#include "AnalysisSteering.h"
#include "AnalysisFactory.h"
#include "EventSource.h"
#include "SourceFactory.h"
#include "EventDump.h"
#include "ParticleMass.h"
#include "Event.h"

int main(int argc, char *argv[]){

    //raccoglie i parametri iniziali in input dal terminale
    AnalysisInfo *info = new AnalysisInfo(argc, argv);

    //Elabora i parametri iniziali e crea il costruttore in base all'input dell'utente
    EventSource *es = SourceFactory::create(info);


    //Creazione degli analizzatori 
    std::vector<AnalysisSteering*> aList = AnalysisFactory::create( info );


    for(auto as : aList){
        as ->beginJob();
    }

    //Chiama la funzione "run" in EventSource
    es->run();

    for (auto as : aList){
        as ->endJob();
        delete as;
    }

    delete es;

    return 0;
}