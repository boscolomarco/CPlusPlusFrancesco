#ifndef PARTICLEMASS_H
#define PARTICLEMASS_H

#include "AnalysisSteering.h"
#include <string>
#include <vector>

class Event;
class MassMean;
class TH1F;

class ParticleMass: public AnalysisSteering{

public:

    ParticleMass();
    ~ParticleMass() override;

    // function to be called at execution start
    void beginJob() override;
    // function to be called at execution end
    void endJob() override;
    // function to be called for each event
    void process( const Event& ev ) override;

private:

    struct Particle{
        std::string histName;   //Nome dell'istogramma
        MassMean *massMean;
        TH1F *hMean;
    };

    std::vector<Particle*> pList;

    void pCreate (const std::string &histName, float min, float max);

};

#endif