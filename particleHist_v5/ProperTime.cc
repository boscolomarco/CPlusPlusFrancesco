#include "ProperTime.h"
#include "Event.h"
#include "Utilities.h"
#include "Constant.h"
#include <iostream>
#include <cmath>
#include "ParticleReco.h"

// constructor
ProperTime::ProperTime() {
}


// destructor
ProperTime::~ProperTime() {
}


// recompute tag informations for new event
void ProperTime::update( const Event& ev )
{
  static ParticleReco* part_rec = ParticleReco::instance();

  double e = part_rec->Part_Energy();
  double m = part_rec->Part_Mass();
  double x = ev.getX();
  double y = ev.getY();
  double z = ev.getZ();
  double p = sqrt(pow(e, 2) - pow(m, 2));
  double d = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
  double c = Constant::lightVelocity;

  time = d * m / ( p*c );

  return;
}

// return particle type
ProperTime::ParticleType ProperTime::Part_Type()
{
  // check for new event and return result
  check();
  return particleType;
}


// return particle energy
double ProperTime::Part_Energy()
{
  // check for new event and return result
  check();
  return particleEnergy;
}


// return particle mass
double ProperTime::Part_Mass()
{
  // check for new event and return result
  check();
  return particleMass;
}

double ProperTime::decayTime(){
  // check for new event and return result
  check();
  return time;
}