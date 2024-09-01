#include "Event.h"


// constructor
Event::Event(int n, float x, float y, float z):
 // initializations
 evId(n),
 X(x), Y(y), Z(z)
 {
  p.reserve(10);
}


// destructor
Event::~Event() {
}


void Event::add(int charge, float px, float py, float pz) {

  // check for the number of particles, if maximum reached do nothing
  // and return
  if(p.size() < 10){

    // create the new particle and fill with data
    Particle particle;
    particle.charge = charge;
    particle.p_x = px;
    particle.p_y = py;
    particle.p_z = pz;

    p.push_back(particle);

    nPar ++;

  }

}


// get event id.
int Event::eventNumber() const {
  return evId;
}


// get decay point coordinates 
float Event::getX() const{
  return X;
}

float Event::getY() const{
  return Y;
}

float Event::getZ() const{
  return Z;
}

// get number of particles
int Event::nParticles() const{
  return nPar;
}

// get particle

const Event::Particle* Event::particle( unsigned int i ) const{
  if (i  < p.size()){
    //CAPISCI BENE PERCHè LA REFERENCE!!!
    return &p[i];
    }
  else 
    return nullptr;
}



