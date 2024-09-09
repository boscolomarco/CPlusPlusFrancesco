#include "TH1F.h"
#include "ParticleMass.h"
#include "AnalysisFactory.h"
#include "MassMean.h"
#include "ParticleReco.h"
#include "AnalysisInfo.h"

#include <iostream>
#include <fstream>

#include "../util/include/TFileProxy.h"

double mass(const Event &ev);

// concrete factory to create a ParticleMass analyzer
class ParticleMassFactory:  public AnalysisFactory::AbsFactory{
 public:
  // assign "plot" as name for this analyzer and factory
  ParticleMassFactory(): AnalysisFactory::AbsFactory( "plot" ) {}            //Il nome della AbsFactory è "plot" in questo caso
  // create a ParticleMass when builder is run
  AnalysisSteering* create( const AnalysisInfo* info ) override {
    return new ParticleMass( info );
  }
};
// create a globa ParticleMassFactory, so that it is created and registered 
// before main execution start:
// when the AnalysisFactory::create function is run,
// a ParticleMassFactory will be available with name "plot".
static ParticleMassFactory er;


ParticleMass::ParticleMass(const AnalysisInfo *info):
    AnalysisSteering(info){}

ParticleMass::~ParticleMass(){

}

void ParticleMass::beginJob(){

    // leggo i range a partire da massRanges.txt
    std::ifstream file(aInfo->value("massRanges").c_str());
    std::string name;
    double Min;
    double Max;
    while (file >> name >> Min >> Max)
    {
       pCreate(name, Min, Max);
    }

    return;
}

void ParticleMass::endJob(){

    // save current working area
    TDirectory* currentDir = gDirectory;
    // open histogram file
    TFile* file = new TFile( "hist.root", "CREATE" );

    for(Particle *pMean : pList){

        //Calcola i valori
        pMean ->massMean -> compute();

        double mean = pMean -> massMean -> mMean();
        double RMS = pMean -> massMean -> mRMS();

        std::cout << mean << " " << RMS << std::endl;


        pMean -> hMean -> Write();

    }

    file -> Close();
    delete file;

    currentDir -> cd();

    return;
}

void ParticleMass::update(const Event &ev){

    static ParticleReco* Part_Reco = ParticleReco::instance();
    double m = Part_Reco->Part_Mass();

    for(Particle *pParticle : pList){
        if(pParticle -> massMean -> add(ev))
            pParticle -> hMean -> Fill(m);
    }
    return;
}

void ParticleMass::pCreate(const std::string &histName, float min, float max){

    //devo fare questo per rendere valido il nome e il titolo dell'istogramma (deve essere una stringa tipo c_strf)
    const char *hName = histName.c_str();

     //Creo un nuovo puntatore alla struct Particle:
     Particle *part = new Particle;

     //Riempio la struttura
     part -> histName = histName;
     part -> massMean = new MassMean(min, max);
     //Creo l'istogramma:
     part -> hMean = new TH1F(hName, hName, 150, min, max);

     pList.push_back(part);
    
}