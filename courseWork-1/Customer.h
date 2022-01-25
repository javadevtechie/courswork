#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Customer
{
    public:
        Customer();

        string GetbookingId() { return bookingId; }
        void SetbookingId(string val) { bookingId = val; }
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
        void menu();
        void mybookings();


    protected:

    private:
        string bookingId;
        string eventID;
        string eventName;
        string eventType;
        string dateOnBooked;
        string noOfTicketsBooked;
        string status;
};

#endif // CUSOTMER_H
