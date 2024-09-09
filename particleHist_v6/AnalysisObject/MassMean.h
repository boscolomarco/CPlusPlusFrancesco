#ifndef MassMean_h
#define MassMean_h

class Event;

class MassMean {

 public:

  MassMean(float min, float max);       // range delle masse 
  ~MassMean();

  bool add(const Event& ev);      // aggiungi dati a nuovo evento 
  void compute();                   // calcola medua e rms 

  int nEvents();                   // ritorna il numero di eventi accettati
  double mMean() ;                  // ritona massa media
  double mRMS();                   // ritorna rms 
 private:

  float minInvMass;      //Estremo inferiore e superiore del range di massa 
  float maxInvMass; 

  int numberOfEvents;           // numero di eventi accettati
  double sumMasses;       // somma delle masse e delle masse quadrate 
  double sumSquareMasses; 

  double meanMass;         
  double RMS;              

};

#endif

