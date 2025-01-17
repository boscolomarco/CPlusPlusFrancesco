#include "MassMean.h"
#include "../AnalysisFramework/Event.h"
#include "ParticleReco.h"

#include <cmath>

double mass(const Event &ev);

// constructor
MassMean::MassMean(float min, float max):
  // initializations
  minInvMass(min), maxInvMass(max),
  numberOfEvents(0), sumMasses(0), sumSquareMasses(0),
  meanMass(0), RMS(0)
{

}


// destructor
MassMean::~MassMean() {

}


// add data from a new event
bool MassMean::add(const Event& ev) {

  static ParticleReco* Part_Reco = ParticleReco::instance();
  double m = Part_Reco->Part_Mass();
  // check for mass being in range
  if ((m > minInvMass) && (m < maxInvMass)){
    
    // update number of events and sums
    sumMasses += m;
    sumSquareMasses += pow(m, 2);
    numberOfEvents++;

    return true;
  }
  else 
    return false;

}


// compute mean and rms
void MassMean::compute() {
  meanMass = sumMasses / numberOfEvents;
  RMS = sqrt(1.0/numberOfEvents * sumSquareMasses - pow(meanMass, 2));
}


// return number of selected events
int MassMean::nEvents(){
  return numberOfEvents;
}


// return mean and rms
double MassMean::mMean() {
  return meanMass;
}

double MassMean::mRMS(){
  return RMS;
}

