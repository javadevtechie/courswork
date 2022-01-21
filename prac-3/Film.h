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
};
#endif
