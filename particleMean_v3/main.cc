#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Event.h"
#include "Utilities.h"
#include "Constant.h"
#include "MassMean.h"

const Event *read(std::ifstream &file);
void dump (const Event &ev);


int main(int argc, char* argv[]) {

  // Apro file di input
  const std::string name = argv[1];
  std::ifstream file(name.c_str());

  // Creo gli oggetti MassMean

  MassMean K(0.495, 0.5);
  MassMean Lambda(1.115, 1.116);
  

  // loop degli eventi
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
  

  //Stampo gli eventi selezionati e i risultati di entrambe le particelle
  double KMean = K.mMean();
  double KRMS = K.mRMS();
  double LambdaMean = Lambda.mMean();
  double LambdaRMS = Lambda.mRMS();

  std::cout << KMean << " " << KRMS << std::endl;
  std::cout << LambdaMean << " " << LambdaRMS << std::endl;
  

  return 0;

}

