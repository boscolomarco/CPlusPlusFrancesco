#include <iostream>
#include "MassMean.h"
#include "Event.h"
#include "Utilities.h"
#include "Constant.h"

#include <cmath>

double mass(const Event &ev);

// costruttore
MassMean::MassMean(float min, float max):
  // inizializzatori
  minInvMass(min), maxInvMass(max),
  numberOfEvents(0), sumMasses(0), sumSquareMasses(0),
  meanMass(0), RMS(0)
{

}


// distruttore
MassMean::~MassMean() {

}


// aggiungo dati all'eventi 
void MassMean::add(const Event& ev) {

  double m = mass(ev);
  // controllo che la massa invariante sia nel range prestabilito
  if ((m > minInvMass) && (m < maxInvMass)){
    
    // aggiorno gli aventi accettati
    sumMasses += m;
    sumSquareMasses += pow(m, 2);
    numberOfEvents++;
  }

}


// Cacolo le masse invarianti 
void MassMean::compute() {
  meanMass = sumMasses / numberOfEvents;
  RMS = sqrt(1.0/numberOfEvents * sumSquareMasses - pow(meanMass, 2));
}


int MassMean::nEvents(){
  return numberOfEvents;
}


double MassMean::mMean() {
  return meanMass;
}

double MassMean::mRMS(){
  return RMS;
}

