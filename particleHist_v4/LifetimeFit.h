#ifndef LifetimeFit_h
#define LifetimeFit_h

class Event;

class LifetimeFit {

 public:

  LifetimeFit(float min, float max);       // range delle masse 
  ~LifetimeFit();

  bool add(const Event& ev);      // aggiungi dati a nuovo evento 
  void compute();                   // calcola medua e rms 

  int nEvents();                   // ritorna il numero di eventi accettati

 private:

  float minInvMass;      //Estremo inferiore e superiore del range di massa 
  float maxInvMass; 

  int numberOfEvents;           // numero di eventi accettati
            

};

#endif

