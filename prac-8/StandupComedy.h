#ifndef STANDUPCOMEDY_H
#define STANDUPCOMEDY_H
#include "StandupComedy.h"
#include "Event.h"
using namespace std;
class StandupComedy : public Event
{
    public:
        StandupComedy();


        string Getseats() { return seats; }
        void Setseats(string val) { seats = val; }



    private:
        string seats;
};

#endif // STANDUPCOMEDY_H
