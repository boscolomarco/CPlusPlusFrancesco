#include <iostream>
#include <fstream>


//Dichiaro le due strutture
struct Particle;
struct Event;

//Funzioni
const Event *read(std::ifstream &file);
void dump (const Event &ev);
void clear(const Event *ev);


int main(int argc, char *argv[]){

    const char *data = argv[1];
    std::ifstream file(data);

    const Event *ev;


    while((ev = read(file)) != nullptr){
        dump(*ev);
        clear(ev);
    }


    return 0;
}