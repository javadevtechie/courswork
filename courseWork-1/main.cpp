#include <iostream>
#include "Event.h"
#include "Film.h"
#include "StandupComedy.h"
#include <string>
#include<iomanip>
#include<bits/stdc++.h>
#include "TheaterBooking.h"
using namespace std;

template <typename T>
void getChoice(T& choice , const string message)
{

    cout<< message;
    cin>>  choice;
    while(!cin.good())
    {
        cout<<"ERROR: Faulty Input! try again .."<<"\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<< "Enter Choice ";
        cin>> choice;
    }
    cin.clear();
    cin.ignore(INT_MAX, '\n');
}

int main()
{
//    int ch;
//    string name;
//
//    string eventStartDate,eventEndDate,eventName,seats;
//    cout <<" 1. Film \n 2. StandUp Comedy \n 3. Live Music"<<endl;
//    getChoice(name, "Please enter the name:");
//    cout<< "name:"<<name;
//
//
//    getChoice(ch,"Please enter the choice: " );
//    switch(ch)
//    {
//    case 1:
//    {
//        cout<<"Case 1";
//        break;
//    }
//    case 2:
//    {
//        cout<<"Case 2";
//        break;
//    }
//    }
 TheaterBooking t;
    t.mainMenu();

}



