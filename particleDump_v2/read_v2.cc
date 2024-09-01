#include <iostream>
#include <fstream>

#include "Struct.h"

const Event *read(std::ifstream &file){

    Event *ev;
    int input;

    if(file >> input){
        ev = new Event;
    }
    else{
        return nullptr;
    }

    ev -> evId = input;                                     //Dal file prende l'identificativo
    file >> ev -> x >> ev -> y >> ev -> z;                  //Dal file prende le 3 coordinate x, y, z
    file >> ev -> nPar;                                      //Dal file prende il numero di particelle decadute
    

    ev -> p = new Particle *[ev -> nPar];                                   //***
    for(int i = 0; i < ev->nPar; ++i){

        Particle *prt = new Particle;
        file >> prt -> charge >> prt -> p_x >> prt -> p_y >> prt ->p_z;

        ev -> p[i] = prt;
    }

    return ev;

}
/*
*** Da ev.p (definito nella struct Event) creo un nuovo array di strutture di dimensioni nPar;
ciclo tra gli nPar e quindi creo (dentro al ciclo for) un nuovo arogmento per la struttura Particle (come quando deifnisco
una struttura normalmente). Quindi inserisco nella struttura carica e momento e poi alla fine del ciclo INSERISCO NELL'IESIMO 
ELEMENTO DI p (PUNTATORE DI ARRAY IN EVENT) L' "ARGOMENTO DELLA STRUTTURA DI PARTICLE"


*/