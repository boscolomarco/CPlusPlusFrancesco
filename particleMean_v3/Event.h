#include <vector>

#ifndef Event_h
#define Event_h

class Event {

 public:

  // Costruttore
  Event(int n, float x, float y, float z);       // Crea un evento con numero "n" e coordinate x, y, z

  // Distruttore
  ~Event();

   // Struttura contiene tutte le informazioni sulle particelle decadute
  // carica elettrica e trimomento 
  struct Particle {
    int charge;
    float p_x, p_y, p_z;
  };


  typedef const Particle* part_ptr;

  // Aggiunge un punto all'evento
  void add(int charge, float px, float py, float pz);

  //Prende l'identificativo
  int eventNumber() const;

  // Prende i punti di decaidmento 
  float getX() const;
  float getY() const;
  float getZ() const;

  int nParticles() const;

  part_ptr particle(unsigned int i) const;

 private:

  // Informazioni realtive all'evenit
  int evId;                     //ID dell'evento
  float X, Y, Z;                // punto di decaidmento
  int nPar;
  std::vector<Particle> p;

  
};

#endif

