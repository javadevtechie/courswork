#include <iostream>
#include "TheaterBooking.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;
int main()
{

    cout<<"Welcome to Theater Booking system"<<endl;
    TheaterBooking t;
    t.mainMenu();
//    time_t now = time(0);
//    tm *ltm = localtime(&now);
//    string currentDate=std::to_string(ltm->tm_mday) + "/" + std::to_string(1 + ltm->tm_mon)+"/"+std::to_string(1900 + ltm->tm_year);
//    cout << currentDate;
////    cout << "Year:" << 1900 + ltm->tm_year<<endl;
////    cout << "Month: "<< 1 + ltm->tm_mon<< endl;
////    cout << "Day: "<< ltm->tm_mday << endl;
////    cout << "Time: "<< 5+ltm->tm_hour << ":";
////    cout << 30+ltm->tm_min << ":";
////    cout << ltm->tm_sec << endl;
    return 0;
}



