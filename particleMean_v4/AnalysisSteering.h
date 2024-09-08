#ifndef AnalysisSteering_h
#define AnalysisSteering_h

class Event;

class AnalysisSteering{

public:
    AnalysisSteering();

    AnalysisSteering(const AnalysisSteering &x) = delete;
    AnalysisSteering &operator=(const AnalysisSteering &x) = delete;

    virtual ~AnalysisSteering();

    //Function to call when execution starts/ends
    virtual void beginJob() = 0;        //Pure virtual function!!
    virtual void endJob() = 0;

    //Function to call for each event
    virtual void process(const Event &ev) = 0;
};

#endif