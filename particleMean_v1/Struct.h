#ifndef Struct_h
#define Struct_h

//Struttura degli elementi della particella decaduta
struct Particle{

    int charge;
    float p_x, p_y, p_z;
};

//struttura per l'evento della particella
struct Event{

    int evId;                       //Identificativo del decadimento     
    int nPar;                       //Numero di Particelle
    float x, y, z;                  //coordinate di dedadimento

    Particle **p;
};

#endif