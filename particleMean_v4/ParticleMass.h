#ifndef ParticleMass_h
#define ParticleMass_h

#include "AnalysisSteering.h"
#include <vector>

class Event;
class MassMean;

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
    std::vector<MassMean*> pList;
};

#endif