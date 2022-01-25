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
    void updateBooking(int bookingId,string status);
    void updateEvent(string eventId,string seats);
    string getEventByid(string eventId);
protected:

private:
};

#endif // THEATERBOOKING_H
