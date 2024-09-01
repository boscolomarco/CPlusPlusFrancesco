#include "ParticleMass.h"

#include "Event.h"
#include "MassMean.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

ParticleMass::ParticleMass(){

}

ParticleMass::~ParticleMass(){

}

void ParticleMass::beginJob(){

    pList.push_back(new MassMean(0.495, 0.5));
    pList.push_back(new MassMean(1.115, 1.116));

    return;
}

void ParticleMass::endJob(){

    for(MassMean *pMean : pList){
        pMean -> compute();

        double mean = pMean -> mMean();
        double rms = pMean -> mRMS();

        std::cout << mean << " " << rms << std::endl;

    }

    return;
}

void ParticleMass::process(const Event &ev){

    for(MassMean *pMean : pList){
        pMean -> add(ev);
    }
    return;
}