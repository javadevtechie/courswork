#include "TheaterUtility.h"
#include<bits/stdc++.h>
#include <string>
#include <iostream>
#include "Customer.h"
TheaterUtility::TheaterUtility()
{

}
int TheaterUtility::getInputForChoice(int choice,int maxChoice, string message)
{
    cout<< message;
    cin>>  choice;
    while(!cin.good())
    {
        cout<<"ERROR: Faulty Input! try again .."<<"\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<< message ;
        cin>> choice;
    }
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    return choice;
}
int TheaterUtility::getInputForInt(int choice, string message)
{
    cout<< message;
    cin>>  choice;
    while(!cin.good())
    {
        cout<<"ERROR: Faulty Input! try again .."<<"\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<< message ;
        cin>> choice;
    }
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    return choice;
}
string TheaterUtility::getInputForString(string input, string message)
{

    cout<< message;
    cin>>  input;
    while(!cin.good())
    {
        cout<<"ERROR: Faulty Input! try again .."<<"\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<< "Enter input ";
        cin>> input;
    }
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    return input;
}
string TheaterUtility::getInputForEventId(string eventId,string message)
{

    cout<< message;
    cin>>  eventId;
    while(!isValidEventId(eventId))
    {
        cout<<"ERROR: invalid eventId! try again .."<<"\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<<"Enter Event Id: ";
        cin>> eventId;
    }
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    return eventId;
}
bool TheaterUtility::isValidEventId(string eventId)
{
    TheaterUtility tu;
    string myText;
    ifstream MyReadFile("events.txt");
    while (getline (MyReadFile, myText))
    {
        vector<string> token=tu.getStringToken(myText);
        if (eventId.compare(token[0])==0)
        {

            MyReadFile.close();
            return true;
        }
    }
    MyReadFile.close();
    return false;
}


vector<string> TheaterUtility::getStringToken(string myText)
{
    vector <string> tokens;
    stringstream check1(myText);

    string intermediate;
    while(getline(check1, intermediate, '|'))
    {
        tokens.push_back(intermediate);
    }

    return tokens;
}
vector<string> TheaterUtility::getEventById(string eventId)
{

    TheaterUtility tu;
    string myText;
    ifstream MyReadFile("events.txt");
    vector<string> token;
    while (getline (MyReadFile, myText))
    {
        token=tu.getStringToken(myText);
        if (eventId.compare(token[0])==0)
        {
            MyReadFile.close();
            return token;
        }
    }
    MyReadFile.close();
    return token;

}


int TheaterUtility:: getInputForSeats(string eventId,int seats,string message)
{
    seats=getInputForInt(seats,"Enter No.of seats:");
    vector<string> token=getEventById(eventId);
    while(std::stoi(token[5])<seats)
    {
        cout<<"Entered seats are more than available seats \n";
        seats=getInputForInt(seats,"Enter No.of seats: ");
    }
    return seats;
}

int TheaterUtility:: getRand()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    return std::rand() ;
}
