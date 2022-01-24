#ifndef THEATERUTILITY_H
#define THEATERUTILITY_H
#include <string>
#include <iostream>
using namespace std;


class TheaterUtility
{

    public:
        TheaterUtility();
       int getInputForInt(int choice ,  string message);
       string getInputForString(string choice ,  string message);
};

#endif // THEATERUTILITY_H
