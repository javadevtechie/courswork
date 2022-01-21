#ifndef THEATERBOOKING_H
#define THEATERBOOKING_H
#include "Event.h"
class TheaterBooking
{
public:
    TheaterBooking();
    void menu();
    void subMenu();
    void addBooking(Event e);
    void listOfAllEvents();
    void searchByEventName();

protected:

private:
};

#endif // THEATERBOOKING_H
