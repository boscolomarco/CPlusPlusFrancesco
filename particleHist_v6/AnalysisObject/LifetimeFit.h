#ifndef LifetimeFit_h
#define LifetimeFit_h

#include <iostream>
#include <vector>

class Event;

class LifetimeFit {

 public:

  LifetimeFit(float min, float max, double t_min, double t_max,
                 double range_min, double range_max, double scan_step); // mass range      // range delle masse 
  ~LifetimeFit();

  bool add(const Event& ev);           // aggiungi dati a nuovo evento 
  void compute();                      // calcola medua e rms 
  int nEvents() const;                // numero di eventi accettati


  double lifeTime() const;            // ritorna tempo medio di vita 
  double lifeTimeError() const;       // ritorna errore tempo medio di vita

 private:

  float minInvMass;      //Estremo inferiore e superiore del range di massa 
  float maxInvMass; 

  double t_Min;                 // min time range
  double t_Max;                 // max time range
  double scan_Min;              // min scan range
  double scan_Max;              // max scan range
  double scan_Step;             // scan step

  double mean_Life;
  double rms_Life;

  std::vector<double> decay_Times;
            

};

#endif

