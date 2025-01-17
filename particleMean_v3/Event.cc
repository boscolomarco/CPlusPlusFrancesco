#include "Event.h"


// Costruttore
Event::Event(int n, float x, float y, float z):
 // inizializzatori
 evId(n),
 X(x), Y(y), Z(z)
 {
  p.reserve(10);
}


// distruttore
Event::~Event() {
}


void Event::add(int charge, float px, float py, float pz) {

  
  if(p.size() < 10){

    Particle particle;
    particle.charge = charge;
    particle.p_x = px;
    particle.p_y = py;
    particle.p_z = pz;

    p.push_back(particle);

    nPar ++;

  }

}


// Identificativo dell'evento
int Event::eventNumber() const {
  return evId;
}


// Coordinate di decadimento
float Event::getX() const{
  return X;
}

float Event::getY() const{
  return Y;
}

float Event::getZ() const{
  return Z;
}


int Event::nParticles() const{
  return nPar;
}


const Event::Particle* Event::particle( unsigned int i ) const{
  if (i  < p.size()){
    return &p[i];
    }
  else 
    return nullptr;
}



