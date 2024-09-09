#include "ParticleLifetime.h"
#include "AnalysisFactory.h"
#include "AnalysisInfo.h"
#include "Constant.h"
#include <iostream>
#include "Event.h"
#include "LifetimeFit.h"
#include "TH1F.h"
#include "ProperTime.h"
#include <string>
#include "../util/include/TFileProxy.h"

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

    //Invoco la funzione pCreate(nome, min, max)
    pCreate("K", 0.495, 0.5, 10.0, 500.0);
    pCreate("Lambda", 1.115, 1.116, 10.0, 1000.0);

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
        TH1F *hMean = part -> hMean;

        unsigned int n_part = part->lifetimeFit->nEvents();

        // print results on screen
        std::cout << "(decay time) n_part\t" << n_part << std::endl;

        //Calcola i valori
        lifetimeFit -> compute();

        hMean -> Write();

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

void ParticleLifetime::pCreate(const std::string &histName, float min, float max, double timeMin, double timeMax){


     //Creo un nuovo puntatore alla struct Particle:
     Particle *part = new Particle;

     //Riempio la struttura
     std::string h_name = "time"+histName;
     part -> lifetimeFit = new LifetimeFit(min, max);
     //Creo l'istogramma:
     part -> hMean = new TH1F(h_name.c_str(), h_name.c_str(), 150, min, max);

     pList.push_back(part);
    
}