#include "ParticleLifetime.h"
#include "../AnalysisFramework/AnalysisFactory.h"
#include "../AnalysisFramework/AnalysisInfo.h"
#include "../AnalysisFramework/Event.h"
#include "../AnalysisObject/LifetimeFit.h"
#include "TH1F.h"
#include "../AnalysisObject/ProperTime.h"
#include "../../util/include/TFileProxy.h"

#include <string>
#include <iostream>
#include <fstream>

double mass(const Event &ev);

// concrete factory to create a ParticleMass analyzer
class ParticleLifetimeFactory:  public AnalysisFactory::AbsFactory{
 public:
  // assign "plot" as name for this analyzer and factory
  ParticleLifetimeFactory(): AnalysisFactory::AbsFactory( "time" ) {}            //Il nome della AbsFactory è "plot" in questo caso
  // create a ParticleMass when builder is run
  AnalysisSteering* create( const AnalysisInfo* info ) override {
    return new ParticleLifetime( info );
  }
};
// create a globa ParticleLifetimeFactory, so that it is created and registered 
// before main execution start:
// when the AnalysisFactory::create function is run,
// a ParticleLifetimeFactory will be available with name "plot".
static ParticleLifetimeFactory er;


ParticleLifetime::ParticleLifetime(const AnalysisInfo *info):
    AnalysisSteering(info){}

ParticleLifetime::~ParticleLifetime(){

}

void ParticleLifetime::beginJob(){

    // leggo i range a partire da massRanges.txt
    std::ifstream file(aInfo->value("timeRanges").c_str());
    std::string name;
    double Min, Max;
    double time_Min, time_Max;
    double scan_Min, scan_Max;
    double scan_Step;

    while (file >> name >> Min >> Max >> time_Min >> time_Max >> scan_Min >> scan_Max >> scan_Step)
    {
       pCreate(name, Min, Max, time_Min, time_Max, scan_Min, scan_Max, scan_Step);
    }

    return;
}

void ParticleLifetime::endJob(){

    // save current working area
    TDirectory* currentDir = gDirectory;
    // uso un Proxy per salvare tutti gli istogrammi nello stesso file
    std::string name = "hist.root";

    TFileProxy* file = new TFileProxy(name.c_str(), "CREATE");

    for(Particle *part : pList){

        //LifetimeFit è il puntatore alla classe LifetimeFit (definiti nella struct Particle)
        //hMean è il puntatore all'istogramma
        LifetimeFit *lifetimeFit = part -> lifetimeFit;
        //TH1F *hMean = part -> hMean;

        part->lifetimeFit->compute();

        unsigned int n_part = part->lifetimeFit->nEvents();

        // print results on screen
        std::cout << "Numero di particelle: " << n_part << std::endl;
        part -> hMean -> Write();

    }

    file -> Close();
    delete file;

    currentDir -> cd();

    return;
}


void ParticleLifetime::update(const Event &ev)
{
    static ProperTime* time_rec = ProperTime::instance();

    // loop over particles
    for(Particle* part: pList)
        // check if event is compatible
        if(part->lifetimeFit->add(ev))
            // fill TH1F
            part-> hMean->Fill(time_rec->decayTime());

    return;
}

void ParticleLifetime::pCreate(const std::string &histName, float min, float max, double timeMin, double timeMax, double scanMin, double scanMax, double scanStep){


     //Creo un nuovo puntatore alla struct Particle:
     Particle *part = new Particle;

     //Riempio la struttura
     std::string h_name = "time"+histName;
     part -> lifetimeFit = new LifetimeFit(min, max, timeMin, timeMax, scanMin, scanMax, scanStep);
     //Creo l'istogramma:
     part -> hMean = new TH1F(h_name.c_str(), h_name.c_str(), 150, timeMin, timeMax);

     pList.push_back(part);
    
}