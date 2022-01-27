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
#include <regex>
using namespace std;
TheaterBooking::TheaterBooking()
{
}

void TheaterBooking::mainMenu()
{
    TheaterUtility tu;
    Customer c;
    int ch=0;


    cout<<" 1. Staff \n 2. Customer \n 3. Exit"<<endl;
    ch=tu.getInputForChoice(ch,4,"Please enter the choice: ");
    switch(ch)
    {
    case 1:
        subMenu();
        break;
    case 2:
        c.menu();
        break;
    case 3:
        system("PAUSE");
    }

}

void TheaterBooking::subMenu()
{
    TheaterUtility tu;
    int ch;

    cout <<" 1. Add a booking for an event \n 2. Cancel/Refund a booking \n 3. List all events  \n 4. List details and availability of a given event \n 5. Exit" <<endl;
    ch=tu.getInputForChoice(ch,6,"Please enter the choice: ");
    switch(ch)
    {
    case 1:
        subSubMenu();
        break;
    case 2:
        listOfAllbookedEvents();
        actionOnBooking();
        subMenu();
        break;
    case 3:
        listOfAllEvents();
        subMenu();
        break;
    case 4:
        searchByEventName();
        subMenu();
        break;
    case 5:
        mainMenu();
        break;
    }

}
void TheaterBooking::subSubMenu()
{
    TheaterUtility tu;
    string eventStartDate,eventEndDate,eventName,seats;
    int ch=0;
    do
    {
        cout <<" 1. Film \n 2. StandUp Comedy \n 3. Live Music \n 4.Exit"<<endl;
        ch=tu.getInputForChoice(ch,5,"Please enter the choice: ");
        switch(ch)
        {
        case 1:
        {
            addFilmEvent();
            break;
        }
        case 2:
        {
            addStandUpComedy();
            break;
        }
        case 3:
        {
            addLiveMusic();
            break;
        }
        case 4:
        {
            subMenu();
            break;

        }

        }
    }
    while(ch!=5);
}
void TheaterBooking::addStandUpComedy()
{
    TheaterUtility tu;
    string eventStartDate,eventEndDate,eventName,seats;
    int ch;
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
    cout<<"Event added successfully!"<<endl;

}
void TheaterBooking::addLiveMusic()
{
    TheaterUtility tu;
    string eventStartDate,eventEndDate,eventName,seats;
    int ch;
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
    cout<<"Event added successfully!"<<endl;
}
void TheaterBooking::addFilmEvent()
{
    TheaterUtility tu;
    string eventStartDate,eventEndDate,eventName,seats;
    int ch;
    eventName=tu.getInputForString(eventName,"Please enter Event Name: ");
    seats= std::to_string(tu.getInputForInt(ch,"Enter No.of seats: "));
    eventStartDate=tu.datepicker("Enter Event Start date");
    eventEndDate=tu.datepicker("Enter Event End date");

    Film e1;
    e1.seteventName(eventName);
    e1.seteventId(tu.getRand());
    e1.seteventStartDate(eventStartDate);
    e1.seteventEndDate(eventEndDate);
    e1.settypeOfEvent("Film");
    e1.setnumberOfSeats(seats);
    e1.setfilmType("2D");
    addBooking(e1);
    cout<<"Event added successfully!"<<endl;
}

void TheaterBooking::addBooking(Event e)
{
    string record=std::to_string(e.geteventId())+"|"+e.geteventName()+"|"+e.geteventStartDate()+"|"+e.geteventEndDate()+"|"+e.gettypeOfEvent()+"|"+ e.getnumberOfSeats()+"\n";
    std::ofstream outfile;
    outfile.open("events.txt", std::ios_base::app);
    outfile << record;
}
void TheaterBooking::listOfAllEvents()
{
    const char separator    = ' ';
    const int numWidth      = 13;
    const int nameWidth=15;
    string myText;
    TheaterUtility tu;
    ifstream MyReadFile("events.txt");
    // cout<<left<<setw(nameWidth)<<setfill(separator)<<"Event Id"<<"Event Name"<<"Event Start"<<"Event End"<<"EventType"<<endl;
    while (getline (MyReadFile, myText))
    {
        vector <string> token=tu.getStringToken(myText);
        for(int i=0 ; i <5; i++)
        {
            cout<<token[i]<< "  ";
            // cout << left << setw(numWidth) << setfill(separator) << token[i];
        }
        cout<<endl;
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
        tb.updateBooking(bookingId,"Cancel");
    }
    else if (id==1)
    {
        tb.updateBooking(bookingId,"Confirmed");
        string bookingRec=tb.getBookingById(std::to_string(bookingId));
        vector<string> token= tu.getStringToken(bookingRec);
        string eventId=token[4];
        string seats=token[3];
        tb.updateEvent(eventId,seats);
        tb.subMenu();
    }
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
        if (myText.find(bookingId) != std::string::npos)
        {
            MyReadFile.close();
            return myText;
        }
    }
    MyReadFile.close();
    return myText;

}
string TheaterBooking::getEventByid(string eventId)
{
    string myText;
    ifstream MyReadFile("events.txt");
    while (getline (MyReadFile, myText))
    {
        if (myText.find(eventId) != std::string::npos)
        {
            MyReadFile.close();
            return myText;
        }
    }
    MyReadFile.close();
    return myText;

}
void TheaterBooking::updateBooking(int bookingId,string status)
{
    TheaterBooking tb;
    string rec=tb.getBookingById(std::to_string(bookingId));
    string rec1=rec;
    rec.replace(rec.find("Pending"), sizeof("Pending") - 1, status);
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
    outfile.close();
    remove("events_customer.txt");
    std::rename("temp.txt","events_customer.txt");

}
void TheaterBooking::updateEvent(string eventId,string seats)
{
    TheaterBooking tb;
    TheaterUtility tu;
    string eventRec=tb.getEventByid(eventId);
    vector <string> token=tu.getStringToken(eventRec);
    int rem=std::stoi(token[5])-std::stoi(seats);
    string rec1=eventRec;
    eventRec.replace(eventRec.find("|"+token[5]), sizeof("|"+token[5]) - 1, std::to_string(rem));
}


