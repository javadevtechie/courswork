#include "TheaterBooking.h"
#include <string>
#include "Event.h"
#include <iostream>
#include <fstream>
#include "Film.h"
#include "StandupComedy.h"
#include "LiveMusic.h"
#include "Customer.h"
#include "TheaterUtility.h"
#include<bits/stdc++.h>
#include <regex>
using namespace std;
TheaterBooking::TheaterBooking()
{
}

void TheaterBooking::subMenu()
{
    TheaterUtility tu;
    string eventStartDate,eventEndDate,eventName,seats;
    int ch=0;
    cout <<" 1. Film \n 2. StandUp Comedy \n 3. Live Music"<<endl;
    ch=tu.getInputForInt(ch,"Please enter the choice: ");
    switch(ch)
    {
    case 1:
    {
        eventName=tu.getInputForString(eventName,"Please enter Event Name: ");
        seats= std::to_string(tu.getInputForInt(ch,"Enter No.of seats: "));
        cout <<"Enter Event Start Date :";
        cin >>eventStartDate;
        cout <<"Enter Event EndDate :";
        cin >>eventEndDate;
        Film e1;
        e1.seteventName(eventName);
        e1.seteventId(tu.getRand());
        e1.seteventStartDate(eventStartDate);
        e1.seteventEndDate(eventEndDate);
        e1.settypeOfEvent("Film");
        e1.setnumberOfSeats(seats);
        e1.setfilmType("2D");
        addBooking(e1);
        break;
    }
    case 2:
    {
        eventName=tu.getInputForString(eventName,"Please enter Event Name: ");
        seats= std::to_string(tu.getInputForInt(ch,"Enter No.of seats: "));
        cout <<"Enter Event Start Date"<<endl;
        cin >>eventStartDate;
        cout <<"Enter Event EndDate"<<endl;
        cin >>eventEndDate;
        StandupComedy e1;
        e1.seteventName(eventName);
        e1.seteventId(tu.getRand());
        e1.seteventStartDate(eventStartDate);
        e1.seteventEndDate(eventEndDate);
        e1.settypeOfEvent("StandupComedy");
        e1.setnumberOfSeats( seats);
        addBooking(e1);
        break;
    }
    case 3:
    {

        eventName=tu.getInputForString(eventName,"Please enter Event Name: ");
        seats= std::to_string(tu.getInputForInt(ch,"Enter No.of seats: "));
        cout <<"Enter Event Start Date"<<endl;
        cin >>eventStartDate;
        cout <<"Enter Event EndDate"<<endl;
        cin >>eventEndDate;
        LiveMusic e1;
        e1.seteventName(eventName);
        e1.seteventId(tu.getRand());
        e1.seteventStartDate(eventStartDate);
        e1.seteventEndDate(eventEndDate);
        e1.settypeOfEvent("LiveMusic");
        e1.setnumberOfSeats(seats);
        addBooking(e1);
        break;
    }
    }
}



void TheaterBooking::menu()
{
    TheaterUtility tu;
    int ch;
    do
    {
        cout <<" 1. Add a booking for an event \n 2. Cancel/Refund a booking \n 3. List all events  \n 4. List details and availability of a given event \n  \n 6.Exit" <<endl;
        //cout << "Please enter the choice" <<endl;
        ch=tu.getInputForInt(ch,"Please enter the choice: ");
        switch(ch)
        {
        case 1:
            subMenu();
            break;
        case 2:
            listOfAllbookedEvents();
            actionOnBooking();

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
    TheaterUtility tu;
    Customer c;
    cout<<"Welcome to Theater Booking system"<<endl;
    cout<<" 1. Staff \n 2. Customer "<<endl;
    int ch=0;
    // cin>>ch;
    ch=tu.getInputForInt(ch,"Please enter the choice: ");
    switch(ch)
    {
    case 1:
        menu();
        break;
    case 2:
        c.menu();
//        listOfAllEvents();
//        Customer c1;
//        c1.bookAnEvent();
        break;
    }
}
void TheaterBooking::listOfAllbookedEvents()
{
    string myText;
    ifstream MyReadFile("events_customer.txt");
    while (getline (MyReadFile, myText))
    {
        cout << myText<<endl;
    }
    MyReadFile.close();
}
void TheaterBooking::actionOnBooking()
{
    int bookingId,ch,id;
    TheaterUtility tu;
    TheaterBooking tb;
    bookingId=tu.getInputForInt(id,"Enter bookingId which want Confirm/Reject :");
    while(!tb.isValidBookingId(std::to_string(bookingId)))
    {
        bookingId=tu.getInputForInt(id,"Please try with valid bookingId which want Confirm/Reject :");
    }
    id=tu.getInputForInt(id,"1.Confirm \n2.Cancel \n Please Enter the choice :");
    if(id==2)
    {
        string rec=tb.getBookingById(std::to_string(bookingId));
        string rec1=rec;
        rec.replace(rec.find("Pending"), sizeof("Pending") - 1, "Cancel");
        string myText;
        ifstream MyReadFile("events_customer.txt");
        std::ofstream outfile;
        outfile.open("temp.txt", std::ios_base::app);
        while (getline (MyReadFile, myText))
        {
            if (myText.find(rec1) != std::string::npos)
            {
                outfile<<rec<<endl;
            }
            else
            {
                outfile<<myText<<endl;
            }
        }
        MyReadFile.close();
    }
    remove("events_customer.txt");
    std::rename("temp.txt","events_customer.txt");

}
bool TheaterBooking::isValidBookingId(string bookingId)
{
    string myText;
    ifstream MyReadFile("events_customer.txt");
    while (getline (MyReadFile, myText))
    {
        if (myText.find(bookingId) != std::string::npos && myText.find("Pending") != std::string::npos )
        {
            std::cout << myText << '\n';
            MyReadFile.close();
            return true;
        }
    }
    MyReadFile.close();
    return false;
}

string TheaterBooking::getBookingById(string bookingId)
{
    string myText;
    ifstream MyReadFile("events_customer.txt");
    while (getline (MyReadFile, myText))
    {
        cout<<myText<<bookingId<<endl;
        if (myText.find(bookingId) != std::string::npos)
        {
            MyReadFile.close();
            return myText;
        }
    }
    MyReadFile.close();
    return myText;

}

