#include <iostream>
#include <cmath>

#include "Event.h"
#include "Utilities.h"
#include "Constant.h"


double mass(const Event &ev) {

  // variables to loop over particles
  int pos = 0.0; int neg = 0.0;

  double p_xTot     = 0; 
  double p_yTot     = 0;  
  double p_zTot     = 0;

  double KEnergyTot = 0;                  //Energie totali nell'ipotesi K
  double LEnergyTot = 0;                  //Energie totali nell'ipotesi Lambda
  double KInvMass   = 0;                  //Massa invariante nelle ipotesi K e Lambda
  double LInvMass   = 0;             


  for(int i = 0; i < ev.nParticles(); ++i){

    double energy = 0;
    double PionEnergy = 0;
    double ProtonEnergy = 0;

    const Event::Particle *particle = ev.particle(i);

    if((particle ->charge) == 1){

      PionEnergy = Utilities::Energy(particle ->p_x, particle ->p_y, particle ->p_z, Constant::massPion);          //Energia nell'ipotesi pione
      ProtonEnergy = Utilities::Energy(particle ->p_x, particle ->p_y, particle ->p_z, Constant::massProton);      //Energia nell'ipotesi protone

      KEnergyTot += PionEnergy;                         //Somma all'energia totale nelle due ipotesi
      LEnergyTot += ProtonEnergy;

      p_xTot += particle ->p_x;                         //Momento totale 
      p_yTot += particle ->p_y;
      p_zTot += particle ->p_z;

      pos += 1;                                         //aumenta il contatore di particelle con cariche pos (e poi neg)
    }

    if((particle ->charge) == -1){            //se carica = -1 può essere solo pione

      energy = Utilities::Energy(particle ->p_x, particle ->p_y, particle ->p_z, Constant::massPion);

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
    KInvMass = Utilities::InvMass(KEnergyTot, p_xTot, p_yTot, p_zTot);
    LInvMass = Utilities::InvMass(LEnergyTot, p_xTot, p_yTot, p_zTot);
  }

//Calcola la differenza. Il valore più basso viene stimato essere la massa invariante corrispondente al decadimento di K o L.

  if ((abs(KInvMass - Constant::massK0)) <= abs(LInvMass - Constant::massLambda0)){
    return KInvMass;
  }

  else
    return LInvMass;
    
}