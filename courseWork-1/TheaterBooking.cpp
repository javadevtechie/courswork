#include "TheaterBooking.h"
#include <string>
#include "Event.h"
#include <iostream>
#include <fstream>
#include "Film.h"
#include "StandupComedy.h"
#include "LiveMusic.h"
#include "Cusotmer.h"
using namespace std;
TheaterBooking::TheaterBooking()
{
}

void TheaterBooking::subMenu()
{
    int ch,seats;
    string eventStartDate,eventEndDate,eventName;
    cout <<" 1. Film \n 2. StandUp Comedy \n 3. Live Music"<<endl;
    cout <<" Please enter the choice" << endl;
    cin >> ch;
    switch(ch)
    {
    case 1:
    {
        cout<< "Enter Event Name"<<endl;
        cin>>eventName;
        cout <<"Enter Number of seats"<<endl;
        cin >>seats;
        cout <<"Enter Event Start Date"<<endl;
        cin >>eventStartDate;
        cout <<"Enter Event EndDate"<<endl;
        cin >>eventEndDate;
        Film e1;
        e1.seteventName(eventName);
        e1.seteventId(rand());
        e1.seteventStartDate(eventStartDate);
        e1.seteventEndDate(eventEndDate);
        e1.settypeOfEvent("Film");
        e1.setnumberOfSeats(std::to_string(seats));
        addBooking(e1);
        break;
    }
    case 2:
    {
        cout<< "Enter Event Name"<<endl;
        cin>>eventName;
        cout <<"Enter Number of seats"<<endl;
        cin >>seats;
        cout <<"Enter Event Start Date"<<endl;
        cin >>eventStartDate;
        cout <<"Enter Event EndDate"<<endl;
        cin >>eventEndDate;
        StandupComedy e1;
        e1.seteventName(eventName);
        e1.seteventId(343);
        e1.seteventStartDate(eventStartDate);
        e1.seteventEndDate(eventEndDate);
        e1.settypeOfEvent("StandupComedy");
        e1.setnumberOfSeats(std::to_string(seats));
        addBooking(e1);
        break;
    }
    case 3:
    {
        cout <<"Enter Number of seats"<<endl;
        cout<< "Enter Event Name"<<endl;
        cin>>eventName;
        cout <<"Enter Number of seats"<<endl;
        cin >>seats;
        cout <<"Enter Event Start Date"<<endl;
        cin >>eventStartDate;
        cout <<"Enter Event EndDate"<<endl;
        cin >>eventEndDate;
        LiveMusic e1;
        e1.seteventName(eventName);
        e1.seteventId(343);
        e1.seteventStartDate(eventStartDate);
        e1.seteventEndDate(eventEndDate);
        e1.settypeOfEvent("LiveMusic");
        e1.setnumberOfSeats(std::to_string(seats));
        addBooking(e1);
        break;
    }
    }
}



void TheaterBooking::menu()
{
    int ch;
    cout <<"Welcome to Event Management System"<<endl;
    do
    {
        cout <<" 1. Add a booking for an event \n 2. Cancel/Refund a booking \n 3. List all events  \n 4. List details and availability of a given event \n  \n 6.Exit" <<endl;

        cout << "Please enter the choice" <<endl;
        cin>> ch;
        switch(ch)
        {
        case 1:
            subMenu();
            break;
        case 2:
            break;
        case 3:
            listOfAllEvents();
            break;
        case 4:
            searchByEventName();
            break;
        }
    }
    while(ch!=6);
}
void TheaterBooking::addBooking(Event e)
{
    string record=std::to_string(e.geteventId())+"|"+e.geteventName()+"|"+e.geteventStartDate()+"|"+e.geteventEndDate()+"|"+ e.getnumberOfSeats()+"|"+e.gettypeOfEvent()+"\n";
    std::ofstream outfile;
    outfile.open("events.txt", std::ios_base::app);
    outfile << record;
}
void TheaterBooking::listOfAllEvents()
{
    string myText;
    ifstream MyReadFile("events.txt");
    while (getline (MyReadFile, myText))
    {
        cout << myText<<endl;
    }
    MyReadFile.close();

}
void TheaterBooking::searchByEventName()
{
    string eventName;
    cout<< "Enter Event Name"<<endl;
    cin>>eventName;
    string myText;
    ifstream MyReadFile("events.txt");
    while (getline (MyReadFile, myText))
    {
        if (myText.find(eventName) != std::string::npos)
        {
            std::cout << myText << '\n';
            break;
        }
    }
    MyReadFile.close();

}

void TheaterBooking::mainMenu()
{
    cout<<"Welcome to Theater Booking system"<<endl;
    cout<<" 1. Staff \n 2. Customer "<<endl;
    cout<<"Please enter the choice"<<endl;
    int ch;
    cin>>ch;
    switch(ch)
    {
    case 1:
        menu();
        break;
    case 2:
        listOfAllEvents();


        Cusotmer c1;
        c1.bookAnEvent();
        break;
    }




}
