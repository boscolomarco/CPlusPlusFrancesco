#ifndef MassMean_h
#define MassMean_h

class Event;

class MassMean {

 public:

  // constructor
  MassMean(float min, float max);       // mass range

  // destructor
  ~MassMean();

  void add(const Event& ev);      // add data from a new event
  void compute();                   // compute mean and rms

  int nEvents();                   // return number of accepted events
  double mMean() ;                  // return mean mass
  double mRMS();                   // return rms  mass

 private:

  float minInvMass;      //Estremo inferiore e superiore del range di massa 
  float maxInvMass; 

  int numberOfEvents;           // number of accepted events
  double sumMasses;       // sum of masses
  double sumSquareMasses; // sum of masses square

  double meanMass;         // mean mass
  double RMS;              // rms  mass

};

#endif

