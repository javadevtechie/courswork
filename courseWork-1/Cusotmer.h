#ifndef CUSOTMER_H
#define CUSOTMER_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Cusotmer
{
    public:
        Cusotmer();


        string GeteventID() { return eventID; }
        void SeteventID(string val) { eventID = val; }
        string GeteventName() { return eventName; }
        void SeteventName(string val) { eventName = val; }
        string GeteventType() { return eventType; }
        void SeteventType(string val) { eventType = val; }
        string GetdateOnBooked() { return dateOnBooked; }
        void SetdateOnBooked(string val) { dateOnBooked = val; }
        string GetnoOfTicketsBooked() { return noOfTicketsBooked; }
        void SetnoOfTicketsBooked(string val) { noOfTicketsBooked = val; }
        string Getstatus() { return status; }
        void Setstatus(string val) { status = val; }

        void bookAnEvent();
        bool isValidEventId(string eventId);
        bool isSeatsAvailable(string eventId,string noOfSeats);

    protected:

    private:
        string eventID;
        string eventName;
        string eventType;
        string dateOnBooked;
        string noOfTicketsBooked;
        string status;
};

#endif // CUSOTMER_H
