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

  void add(int charge, float px, float py, float pz);

  // prende l'Id della particella 
  int eventNumber() const;

  // prende le posizioni di decadimento 
  float getX() const;
  float getY() const;
  float getZ() const;

  // prende il numero di particelle 
  int nParticles() const;

  part_ptr particle(unsigned int i) const;

 private:

  // informazioni realtive ad ogni decaidmento 
  int evId;                     // Identificativo evento 
  float X, Y, Z;                // Coordinate di decadimento

  // particles: numero di particelle e array di puntatori
  int nPar;
  static int maxPar;
  Particle **p;

  
};

#endif

