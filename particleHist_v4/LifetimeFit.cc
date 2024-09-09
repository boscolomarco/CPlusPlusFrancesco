#include <iostream>
#include "LifetimeFit.h"
#include "Event.h"
#include "Utilities.h"
#include "Constant.h"
#include "ParticleReco.h"

#include <cmath>

double mass(const Event &ev);

// constructor
LifetimeFit::LifetimeFit(float min, float max):
  // initializations
  minInvMass(min), maxInvMass(max),
  numberOfEvents(0) {

}


// destructor
LifetimeFit::~LifetimeFit() {

}


// add data from a new event
bool LifetimeFit::add(const Event& ev) {

  static ParticleReco* Part_Reco = ParticleReco::instance();
  double m = Part_Reco->Part_Mass();
  // check for mass being in range
  if ((m > minInvMass) && (m < maxInvMass)){
    
    // update number of events and sums
    numberOfEvents++;

    return true;
  }
  else 
    return false;

}


// compute mean and rms
void LifetimeFit::compute() {
}


// return number of selected events
int LifetimeFit::nEvents(){
  return numberOfEvents;
}

