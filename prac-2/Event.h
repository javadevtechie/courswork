#ifndef EVENT_H
#define EVENT_H

#include <string>

using namespace std;

class Event
{
     private:
        int eventId;
        string eventName;
        string eventStartDate;
        string eventEndDate;
        string numberOfSeats;
        string typeOfEvent;
    public:
        Event();
        int geteventId() { return eventId; }
        void seteventId(int val) { eventId = val; }
        string geteventName() { return eventName; }
        void seteventName(string val) { eventName = val; }
        string geteventStartDate() { return eventStartDate; }
        void seteventStartDate(string val) { eventStartDate = val; }
        string geteventEndDate() { return eventEndDate; }
        void seteventEndDate(string val) { eventEndDate = val; }
        string getnumberOfSeats() { return numberOfSeats; }
        void setnumberOfSeats(string val) { numberOfSeats = val; }
         string gettypeOfEvent() { return typeOfEvent; }
        void settypeOfEvent(string val) { typeOfEvent = val; }

};
#endif
