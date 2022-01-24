#include "Cusotmer.h"
#include "TheaterBooking.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Cusotmer.h"

using namespace std;
Cusotmer::Cusotmer()
{
    //ctor
}
void Cusotmer::bookAnEvent()
{
    cout<<"Enter Event Id which you want to book"<<endl;
    string eventId;
    cin>>eventId;
    if(isValidEventId(eventId))
    {
        cout<<"Event is valid";
    }
    else
    {
        cout<<"Event is not valid";
    }


}
bool Cusotmer::isValidEventId(string eventId)
{
    string myText;
    ifstream MyReadFile("events.txt");
    while (getline (MyReadFile, myText))
    {
        if (myText.find(eventId) != std::string::npos)
        {

            MyReadFile.close();
            return true;
        }
    }
    MyReadFile.close();
    return false;
}


