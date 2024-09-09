#include "LifetimeFit.h"
#include "Event.h"
#include "ParticleReco.h"
#include "ProperTime.h"
#include "QuadraticFitter.h"
#include <cmath>


double mass(const Event &ev);

// constructor
LifetimeFit::LifetimeFit(float min, float max, double t_min, double t_max,
                 double range_min, double range_max, double scan_step):
  // initializations
  minInvMass(min), maxInvMass(max), t_Min(t_min), t_Max(t_max), scan_Min(range_min), scan_Max(range_max), scan_Step(scan_step) {

}


// destructor
LifetimeFit::~LifetimeFit() {

}


// add data from a new event
bool LifetimeFit::add( const Event& ev )
{
    static ParticleReco* part_Rec = ParticleReco::instance();
    static ProperTime* proper_T = ProperTime::instance();
    double m = part_Rec->Part_Mass();
    double time = proper_T->decayTime();

    // controlla se le masse sono nel range corretto
    if( (minInvMass <= m) && (m <= maxInvMass) )
    {
        // controlla se i tempi sono nel range corretto
        if((t_Min <= time) && (time <= t_Max) )
        {
            decay_Times.push_back(time);
            return true;
        }
    }
    return false;
}



// compute mean and rms
void LifetimeFit::compute()
{
    // massima verosimiglianza 

    //Fit parabolico 
    QuadraticFitter qFit;

    for(double t = scan_Min; t < scan_Max; t += scan_Step)
    {
        double L_t = 0;
        double t_i = 0;
        unsigned int i = 0;
        for(i=0; i < decay_Times.size(); i++){
          //trovo il valore t che minimizza la funzione L_t
            t_i = decay_Times[i];
            L_t += ((t_i / t) + log(t) + log(exp(-t_Min / t) - exp(-t_Max /t)));
        }
        qFit.add(t,L_t);
    }
    //a, b, c definiti in QuadraticFitter
    mean_Life  = - qFit.b() / ( 2. * qFit.c());
    rms_Life = 1. / sqrt( 2. * qFit.c());

}

int LifetimeFit::nEvents() const{ 
  return decay_Times.size(); 
}

double LifetimeFit::lifeTime() const{
  return mean_Life;
} 
// return life time error
double LifetimeFit::lifeTimeError() const{ 
  return rms_Life; 
}

