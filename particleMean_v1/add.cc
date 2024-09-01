#include <iostream>
#include <cmath>

#include "Struct.h"

double mass(const Event &ev);

//Non sono sicuro che il filetype sia bool!!

bool add(const Event &ev, double min, double max, double &sum, double &squareSum){

    double m = mass(ev);
    //Controllo che la massa m (derivante dalla funzione mass) sia compresa tra min e max
    if ((m > min) && (m < max)){
        //se lo è aggiorno massa e massa al quadrato 
        sum += m;
        squareSum += pow(m, 2);

        return true;
    }

    else 
        return false;

}


void stats(int n, double &sum, double &squareSum, double &Mean, double &RMS){

    Mean = sum * 1.0/n;
    RMS = sqrt(1.0/n * squareSum - Mean * Mean);

}