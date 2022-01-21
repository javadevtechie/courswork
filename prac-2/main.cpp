#include <iostream>
#include "Event.h"
#include "Film.h"
#include <string>
#include <fstream>
using namespace std;

void mainMenu(){
cout <<"Welcome to Event Management System"<<endl;
cout <<" 1. Add a booking for an event \n 2. Cancel/Refund a booking \n 3. List all events  \n 4. List details and availability of a given event \n 5. load data from a file \n 6. Same data to file" <<endl;

}
void subMenu(){
    int ch,seats;
    cout <<" 1. Film \n 2. StandUp Comedy \n 3. Live Music"<<endl;
    cout <<" Please enter the choice" << endl;
    cin >> ch;
    switch(ch){
    case 1:
        cout <<"Enter Number of seats"<<endl;
        cin >>seats;

    }

}
int main()
{
    int ch;
    mainMenu();
    cout << "Please enter the choice" <<endl;
    cin>> ch;
    switch(ch){
    case 1:
        subMenu();
        break;

    }

   Event e1;
   e1.seteventName("EventName");
   cout <<e1.geteventName();


   Film f1;
   f1.setnumberOfSeats("33");
   f1.settypeOfEvent("film");
   cout << f1.getnumberOfSeats()<<endl;
   cout << f1.gettypeOfEvent()<<endl;


}



