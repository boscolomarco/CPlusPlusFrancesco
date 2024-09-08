#ifndef MassMean_h
#define MassMean_h

class Event;

class MassMean {

 public:

  // Costruttore
  MassMean(float min, float max);       // Range delle masse

  // Distruttore
  ~MassMean();

  void add(const Event& ev);      // Aggiungo dati al nuovo evento
  void compute();                   // Calcolo media e RMS

  int nEvents();                   // Ritorna il numero di eventi accettati
  double mMean() ;                  // Ritorna media e RMS
  double mRMS();                   

 private:

  float minInvMass;      //Estremo inferiore e superiore del range di massa 
  float maxInvMass; 

  int numberOfEvents;           // NUmero di eventi accettati 
  double sumMasses;             // Somma delle masse e somma quadrata delle asse 
  double sumSquareMasses; 

  double meanMass;         // Media delle masse
  double RMS;              // RMS delle masse 

};

#endif

