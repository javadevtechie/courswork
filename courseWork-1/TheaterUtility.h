#ifndef THEATERUTILITY_H
#define THEATERUTILITY_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;


class TheaterUtility
{

public:
    TheaterUtility();
    int getInputForInt(int choice, string message);
    string getInputForString(string choice,  string message);
    string getInputForEventId(string eventId,string message);
    bool isValidEventId(string eventId);
    int getInputForSeats(string eventId,int seats,string message);
    bool isValidEventId(string eventId,int seats);
    //  bool isSeatsValidForEventId(string eventId,int seats);
    vector <string> getStringToken(string record);
    vector <string> getEventById(string eventId);
    int getRand();
    bool isValidBookingId(string bookingId);
    int getInputForChoice(int choice,int maxChoice, string message);
    string datepicker(string message);
    string getTodayDate();
};

#endif // THEATERUTILITY_H
