#ifndef ParticleLifetime_h
#define ParticleLifetime_h

#include "AnalysisSteering.h"
#include "../util/include/ActiveObserver.h"

#include <string>
#include <vector>

class Event;
class LifetimeFit;
class TH1F;
class AnalysisInfo;

class ParticleLifetime: public AnalysisSteering, public ActiveObserver<Event> {

public:

    ParticleLifetime(const AnalysisInfo *info);
    ParticleLifetime(const ParticleLifetime &x)=delete;
    ParticleLifetime& operator=(const ParticleLifetime &x)=delete;
    ~ParticleLifetime() override;

    // function to be called at execution start
    void beginJob() override;
    // function to be called at execution end
    void endJob() override;
    // function to be called for each event
    void update( const Event& ev ) override;

private:

    struct Particle{
        std::string histName;   //Nome dell'istogramma
        LifetimeFit *lifetimeFit;
        TH1F *hMean;
    };

    std::vector<Particle*> pList;

    void pCreate (const std::string &histName, float min, float max, double timeMin, double timeMax, double scan_Min,
                     double scan_Max, double scan_Step);

};

#endif