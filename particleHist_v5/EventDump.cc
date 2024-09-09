#include "EventDump.h"
#include "Event.h"
#include "AnalysisFactory.h"
#include "../util/include/ActiveObserver.h"

#include <iostream>


// concrete factory to create an EventDump analyzer
class EventDumpFactory: public AnalysisFactory::AbsFactory {            //AnalysisFactory presenta nested class 
 public:
  // assign "dump" as name for this analyzer and factory
  EventDumpFactory(): AnalysisFactory::AbsFactory( "dump" ) {}          //Costruttore della classe 
  // create an EventDump when builder is run
  AnalysisSteering* create( const AnalysisInfo* info ) override {        //Esegue override della funzione "create" in AnalysisFactory
    return new EventDump( info );
  }
};
// create a global EventDumpFactory, so that it is created and registered 
// before main execution start:
// when the AnalysisFactory::create function is run,
// an EventDumpFactory will be available with name "dump".
static EventDumpFactory ed;


EventDump::EventDump(const AnalysisInfo *info):
 AnalysisSteering(info){
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
void EventDump::update(const Event &ev){

    std::cout << ev.eventNumber() << std::endl;
    std::cout << ev.getX() << " " << ev.getY() << " " << ev.getZ() << std::endl;

    std::cout << ev.nParticles() << std::endl;


    for(int i = 0; i < ev.nParticles(); ++i){
        const Event::Particle *part = ev.particle(i);

        std::cout << part ->charge << " " << part ->p_x << " " << part ->p_y << " " << part ->p_z << std::endl;
    }
}

