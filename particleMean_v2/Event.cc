#include "Event.h"

//Impongo maxPar pari a 10
int Event::maxPar = 10;

// costruttore
Event::Event(int n, float x, float y, float z):
 // inizializzatori
 evId(n),
 X(x), Y(y), Z(z), nPar(0)
 {
  // alloco memoria di buffer
  p = new Particle *[maxPar];
  //p è un array di pointer, in questo modo lo definisco
}


// distruttore
Event::~Event() {
  // cancella ogni particella nel costruttore
  for(int i = 0; i < nPar; ++i){
    delete p[i];
  }
  // cancella l'array di pointer 
  delete[] p;
}


void Event::add(int charge, float px, float py, float pz) {

  //Controlla il numero di particelle, se il massimo è raggiunto non fa nulla 
  if(nPar < maxPar){

    Particle *particle = new Particle;

    particle ->charge = charge;
    particle ->p_x = px;
    particle ->p_y = py;
    particle ->p_z = pz; 

    //Immagazzino il puntatore alla particella nell'array e incremento il contatore
    p[nPar] = particle;
    nPar++;

  }

}


// get event id.
int Event::eventNumber() const {
  return evId;
}

//Prendo le coordinate di decaidmento
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


// prendo le particelle
const Event::Particle* Event::particle( unsigned int i ) const{
  if (i  < nPar){
    //pointer alla specifica particella 
    return p[i];
    }
  else return nullptr;
}

