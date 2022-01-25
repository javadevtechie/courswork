#ifndef THEATERBOOKING_H
#define THEATERBOOKING_H
#include "Event.h"
#include "Film.h"
class TheaterBooking
{
public:
    TheaterBooking();
    void mainMenu();
    void menu();
    void subMenu();
    void addBooking(Event e);
    void listOfAllEvents();
    void searchByEventName();
    void listOfAllbookedEvents();
    void actionOnBooking();
    bool isValidBookingId(string bookingId);
    string getBookingById(string bookingId);
protected:

private:
};

#endif // THEATERBOOKING_H
