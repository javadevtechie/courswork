#include "TheaterUtility.h"
#include<bits/stdc++.h>
#include <string>
#include <iostream>
TheaterUtility::TheaterUtility()
{

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
        cout<< "Enter Choice ";
        cin>> input;
    }
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    return input;
}
