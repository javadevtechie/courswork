#ifndef FILM_H
#define FILM_H

#include <string>
#include "Event.h"
using namespace std;


class Film : public Event
{
    private:
        string typeOfEvent;
    public:
        Film();
        string gettypeOfEvent() { return typeOfEvent; }
        void settypeOfEvent(string val) { typeOfEvent = val; }



};
#endif
