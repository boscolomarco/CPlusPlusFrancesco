#ifndef AnalysisFactory_h
#define AnalysisFactory_h

#include <string>
#include <vector>
#include <map>

class AnalysisSteering;
class AnalysisInfo;

class AnalysisFactory {

 public:

  AnalysisFactory();
  // deleted copy constructor and assignment to prevent unadvertent copy
  AnalysisFactory           ( const AnalysisFactory& x ) = delete;
  AnalysisFactory& operator=( const AnalysisFactory& x ) = delete;

  virtual ~AnalysisFactory();

  // create all requested analysis objects
  static std::vector<AnalysisSteering*> create( const AnalysisInfo* info );

  // analysis object abstract factory
  class AbsFactory {
   public:
    // Analyzers are registered with a name so that they are actually 
    // created only if, at runtime, their name is listed in the command line
    AbsFactory( const std::string& name ) { registerFactory( name, this ); } //Costruttore con definizione
    virtual ~AbsFactory() {}
    virtual AnalysisSteering* create( const AnalysisInfo* info ) = 0;
  };

 private:

  // function to add analyzer concrete factories
  static void registerFactory( const std::string& name, AbsFactory* f );
  // map to associate analyzer names with corresponding factories
  static std::map<std::string,AbsFactory*>* factoryMap();

};

#endif

