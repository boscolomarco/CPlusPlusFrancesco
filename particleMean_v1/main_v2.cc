#include <iostream>
#include <fstream>


//Dichiaro le due strutture
struct Particle;
struct Event;

//Funzioni
const Event *read(std::ifstream &file);
void dump (const Event &ev);
void clear(const Event *ev);
double mass(const Event &ev);
bool add(const Event &ev, double min, double max, double &sum, double &squareSum);
void stats(int n, double &sum, double &squareSum, double &Mean, double &RMS);


int main(int argc, char *argv[]){

    const char *data = argv[1];
    std::ifstream file(data);

    const Event *ev;

    int count = 1;
    double sumInvMass = 0;
    double sumSquareInvMass = 0;
    double Mean = 0;
    double RMS = 0;


    while((ev = read(file)) != nullptr){
        //dump(*ev);
        if(add(*ev, 0.490, 0.505, sumInvMass, sumSquareInvMass)){

            stats(count, sumInvMass, sumSquareInvMass, Mean, RMS);
            std::cout << count << " " << Mean << " " << RMS << std::endl;
            ++count;
        };
        clear(ev);
       
    }

   


    return 0;
}