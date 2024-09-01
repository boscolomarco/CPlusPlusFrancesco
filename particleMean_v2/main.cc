#include <iostream>
#include <fstream>

#include "Event.h"
#include "Utilities.h"
#include "Constant.h"
#include "MassMean.h"

const Event *read(std::ifstream &file);
void dump (const Event &ev);


int main(int argc, char* argv[]) {

  // open input file
  const char *name = argv[1];
  std::ifstream file(name);

  // create MassMean objects

  MassMean K(0.495, 0.5);
  MassMean Lambda(1.115, 1.116);
  

  // loop over events
  const Event* ev;
  while ( (ev = read(file)) != nullptr ) {
    dump(*ev);
    K.add(*ev);
    Lambda.add(*ev);

    delete ev;      //Chiamo il distruttore di ev
  }

  // compute results
  K.compute();
  Lambda.compute();
  

  // print number of selected events and results for both particles
  double KMean = K.mMean();
  double KRMS = K.mRMS();
  double LambdaMean = Lambda.mMean();
  double LambdaRMS = Lambda.mRMS();

  std::cout << KMean << " " << KRMS << std::endl;
  std::cout << LambdaMean << " " << LambdaRMS << std::endl;
  

  return 0;

}

