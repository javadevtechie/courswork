#include <iostream>
#include "Event.h"

using namespace std;

int main()
{
    Event e;
    int ch;
    while(1){
        cout <<"Welcome To Theater Booking System ";endl;
        cout <<"1. AddBooking for event ";endl;
        cout <<"2. Cancel or Refund a booking ";endl;
        cout <<"3. List all Events ";endl;
        cout <<"4. List Details and availability of given event";endl;
        cout <<"5. Load Data from a file";endl;
        cout <<"6. Save and Exit ";endl;
        cout <<" Enter the Selection"
        cin >> ch;

    }


    return 0;
}
