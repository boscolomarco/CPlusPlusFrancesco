#include <iostream>
#include <fstream>

int read(std::ifstream &ifile, float &x, float &y, float &z, int *elCharge, float *p_x, float *p_y, float *p_z);
void dump(int evNumber, int nParticles, float &x, float &y, float &z, int *elCharge, float *p_x, float *p_y, float *p_z);

int main(int argc, char *argv[]){

    // Prende come input il file che inserisco come secondo argomento nella riga di comando
    const char *part_ev = argv[1];
    //Apre il file di input
    std::ifstream ifile(part_ev);

    // Definisco le variabili.

    int evNumber, nParticles;        // Identificativo dell'evento e numero di particelle per evento
    int elCharge[10];                // Array di cariche elettriche
    float x, y, z;                   // Coordinate di decadimento
    float p_x[10], p_y[10], p_z[10]; // Momenti delle particelle decadute

    while (ifile >> evNumber){
        //Leggo e mando in output gli eventi
        nParticles = read(ifile, x, y, z, elCharge, p_x, p_y, p_z);
        dump(evNumber, nParticles, x, y, z, elCharge, p_x, p_y, p_z);
    }

    return 0;
}