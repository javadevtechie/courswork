#ifndef FILM_H
#define FILM_H

#include <string>
#include "Event.h"
using namespace std;


class Film : public Event
{
private:
    string filmType;//2DOr3D
public:
    Film();
     void setfilmType(string val)
    {
        filmType = val;
    }
    string getfilmType()
    {
        return filmType;
    }

};
#endif
