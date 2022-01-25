#include "Customer.h"
#include "TheaterBooking.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Customer.h"
#include "TheaterUtility.h"
using namespace std;
Customer::Customer()
{
    //ctor
}
void Customer::menu()
{
    TheaterBooking tb;
    TheaterUtility tu;
     int ch=0;
    do
    {
        cout<<" 1. List of Available events \n 2. My Bookings \n 3.Exit "<<endl;
        ch=tu.getInputForInt(ch,"Please enter the choice: ");
        switch(ch)
        {
        case 1:
            tb.listOfAllEvents();
            bookAnEvent();
            break;
        case 2:
            mybookings();
            break;
        }
    }
    while(ch!=3);

}

void Customer::bookAnEvent()
{
    TheaterUtility tu;
    Customer c;
    string eventId;
    int seats;
    eventId=tu.getInputForEventId(eventId,"Enter Event Id: ");
    seats=tu.getInputForSeats(eventId,seats,"Enter No.Of seats: ");
    vector<string> e= tu.getEventById(eventId);
    c.SeteventID(e[0]);
    c.SetbookingId( std::to_string(tu.getRand()));
    c.SetdateOnBooked("01/24/2022");
    c.SeteventName(e[1]);
    c.SetnoOfTicketsBooked(std::to_string(seats));
    c.SeteventType(e[5]);
    // string rec=eventId+"|"+std::to_string(seats)+"|"+e[2]+"|"+e[5];
    string record=c.GetbookingId()+"|"+c.GetdateOnBooked()+"|"+c.GeteventName()+"|"+c.GetnoOfTicketsBooked()+"|"+c.GeteventID()+"|"+"Pending\n";
    std::ofstream outfile;
    outfile.open("events_customer.txt", std::ios_base::app);
    outfile << record;
}
void Customer::mybookings()
{

    string myText;
    ifstream MyReadFile("events_customer.txt");
    while (getline (MyReadFile, myText))
    {
        cout << myText<<endl;
    }
    MyReadFile.close();


}



