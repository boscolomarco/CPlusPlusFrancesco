#ifndef EventDump_h
#define EventDump_h

#include "AnalysisSteering.h"
#include "../util/include/ActiveObserver.h"


class Event;

class EventDump: public AnalysisSteering, public ActiveObserver<Event> {

public:
    EventDump(const AnalysisInfo *info);

    EventDump(const EventDump &x) = delete;
    EventDump& operator=(const EventDump &x) = delete;

    ~EventDump() override;

    // function to be called at execution start
    void beginJob() override;
    // function to be called at execution end
    void endJob() override;
    // function to be called for each event
    void update( const Event& ev ) override;

};

#endif