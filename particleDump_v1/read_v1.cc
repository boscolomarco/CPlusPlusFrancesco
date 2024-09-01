#include <iostream>
#include <fstream>

int read(std::ifstream &ifile, float &x, float &y, float &z, int *elCharge, float *p_x, float *p_y, float *p_z){

    ifile >> x >> y >> z;                                               //Input dal file delle tre coordinate di decadimento

    int nParticles;
    ifile >> nParticles;                                                //Input dal file del numero di partecelle decadute

    for (int j = 0; j < nParticles; ++j){
        ifile >> elCharge[j] >> p_x[j] >> p_y[j] >> p_z[j];             //Input dal file le cariche e i momenti delle particelle decadute 
    }


    return nParticles;
}