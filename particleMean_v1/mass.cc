#include <iostream>
#include <cmath>

#include "Struct.h"

const double massPion    = 0.1395706;   // GeV/c^2
const double massProton  = 0.938272;    // GeV/c^2
const double massK0      = 0.497611;    // GeV/c^2
const double massLambda0 = 1.115683;    // GeV/c^2


double SquaredMomentum(double p_x, double p_y, double p_z){

  return pow(p_x, 2) + pow(p_y, 2) + pow(p_z, 2);
}

// Calcolo l'energia a partire dalla somma quadrata tra momento e massa invariante 
double Energy(double p_x, double p_y, double p_z, double invMass) {
  
  return sqrt(SquaredMomentum(p_x, p_y, p_z) + pow(invMass, 2));
} 

// Calcolo la massa invariante come differeza in auqdratura tra energia e momento
double InvMass(double energy, double p_x, double p_y, double p_z) {

  return sqrt(pow(energy, 2) - SquaredMomentum(p_x, p_y, p_z));
} 

double mass(const Event &ev) {

  // Prendo le particelle dagli eventi 
  typedef const Particle* part_ptr;
  const part_ptr* particles = ev.p;

  //Particle ** particles = ev.p;         //Equivalente alle due righe sopra

  // Variabili da calcolare nel loop
  int pos = 0.0; int neg = 0.0;

  double p_xTot     = 0; double p_yTot     = 0;  double p_zTot     = 0;
  double KEnergyTot = 0;                  //Energie totali nell'ipotesi K e Lambda
  double LEnergyTot = 0;                  
  double KInvMass   = 0;                  //Massa invariante nelle ipotesi K e Lambda
  double LInvMass   = 0;             


  for(int i = 0; i < ev.nPar; ++i){

    double energy = 0;
    double PionEnergy = 0;
    double ProtonEnergy = 0;

    const Particle *particle = particles[i];

    if((particle ->charge) == 1){

      PionEnergy = Energy(particle ->p_x, particle ->p_y, particle ->p_z, massPion);          //Energia nell'ipotesi pione
      ProtonEnergy = Energy(particle ->p_x, particle ->p_y, particle ->p_z, massProton);      //Energia nell'ipotesi protone

      KEnergyTot += PionEnergy;                         //Somma all'energia totale nelle due ipotesi
      LEnergyTot += ProtonEnergy;

      p_xTot += particle ->p_x;                         //Momento totale 
      p_yTot += particle ->p_y;
      p_zTot += particle ->p_z;

      pos += 1;                                         //aumenta il contatore di particelle con cariche pos (e poi neg)
    }

    if((particle ->charge) == -1){            //se carica = -1 può essere solo pione

      energy = Energy(particle ->p_x, particle ->p_y, particle ->p_z, massPion);

      KEnergyTot += energy;
      LEnergyTot += energy;

      p_xTot += particle ->p_x;
      p_yTot += particle ->p_y;
      p_zTot += particle ->p_z;

      neg += 1;

    } 
  }
  
  int a = -1;

  if((neg != 1) || (pos != 1))
    return a;

  if((neg ==1) && (pos == 1)){
    
    //Compute the invariant mass:
    KInvMass = InvMass(KEnergyTot, p_xTot, p_yTot, p_zTot);
    LInvMass = InvMass(LEnergyTot, p_xTot, p_yTot, p_zTot);
  }

//Calcola la differenza. Il valore più basso viene stimato essere la massa invariante corrispondente al decadimento di K o L.

  if ((abs(KInvMass - massK0)) <= abs(LInvMass - massLambda0)){
    return KInvMass;
  }

  else
    return LInvMass;
    
}