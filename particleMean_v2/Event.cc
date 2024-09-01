#include "Event.h"

//Imposto maxPar pari a 10
int Event::maxPar = 10;

// constructor
Event::Event(int n, float x, float y, float z):
 // initializations
 evId(n),
 X(x), Y(y), Z(z), nPar(0)
 {
  // allocate a buffer for particle pointers
  p = new Particle *[maxPar];
  //p è un array di pointer, in questo modo lo definisco
}


// destructor
Event::~Event() {
  // delete all the particle pointers
  for(int i = 0; i < nPar; ++i){
    delete p[i];
  }
  // delete the pointers array
  delete[] p;
}


void Event::add(int charge, float px, float py, float pz) {

  // check for the number of particles, if maximum reached do nothing
  // and return
  if(nPar < maxPar){

    // create the new particle and fill with data
    Particle *particle = new Particle;

    particle ->charge = charge;
    particle ->p_x = px;
    particle ->p_y = py;
    particle ->p_z = pz; 

    // store the new particle pointer in the array and increase counter
    p[nPar] = particle;

    //Incremento 
    nPar++;

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
  if (i  < nPar){
    //pointer alla specifica particella 
    return p[i];
    }
  else return nullptr;
}

