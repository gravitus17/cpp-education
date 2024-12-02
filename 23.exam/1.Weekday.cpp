#include <iostream>

using namespace std;

#define DAY_1 "Monday"
#define DAY_2 "Tuesday"
#define DAY_3 "Wednesday"
#define DAY_4 "Thursday"
#define DAY_5 "Friday"
#define DAY_6 "Saturday"
#define DAY_7 "Sunday"

#define GET_DAY_TEXT(day) DAY_##day

int main() 
{
    int day;

    cout << ("Enter the day of the week: ");
    cin >> day;

    // Output the corresponding day of the week
    switch(day) 
    {
        case 1: cout <<  GET_DAY_TEXT(1) << endl; break;
        case 2: cout <<  GET_DAY_TEXT(2) << endl; break;
        case 3: cout <<  GET_DAY_TEXT(3) << endl; break;
        case 4: cout <<  GET_DAY_TEXT(4) << endl; break;
        case 5: cout <<  GET_DAY_TEXT(5) << endl; break;
        case 6: cout <<  GET_DAY_TEXT(6) << endl; break;
        case 7: cout <<  GET_DAY_TEXT(7) << endl; break;
        default: cout << "Invalid input! Please enter a number between 1 and 7.\n";
    }
}