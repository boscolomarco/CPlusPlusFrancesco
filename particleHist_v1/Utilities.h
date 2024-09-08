#ifndef Utilities_h
#define Utilities_h

#include <cmath>

class Utilities{

public:

    static double SquaredMomentum(double p_x, double p_y, double p_z){

        return pow(p_x, 2) + pow(p_y, 2) + pow(p_z, 2);
    }

    // compute energy from momentum x,y,z components and invariant mass
    static double Energy(double p_x, double p_y, double p_z, double invMass) {
    
        return sqrt(SquaredMomentum(p_x, p_y, p_z) + pow(invMass, 2));
    } 

    // compute invariant mass from momentum x,y,z components and energy
    static double InvMass(double energy, double p_x, double p_y, double p_z) {

        return sqrt(pow(energy, 2) - SquaredMomentum(p_x, p_y, p_z));
    } 


};

#endif