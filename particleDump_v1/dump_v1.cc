#include <iostream>
#include <fstream>

void dump(int evNumber, int nParticles, float &x, float &y, float &z, int *elCharge, float *p_x, float *p_y, float *p_z){

    std::cout << evNumber << std::endl;
    std::cout << x << " " << y << " " << z << std::endl;

    std::cout << nParticles << std::endl;

    for(int j = 0; j < nParticles; ++j){
        std::cout << elCharge[j] << " " << p_x[j] << " " << p_y[j] << " " << p_z[j] << std::endl;
    }

}