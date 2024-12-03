#include <iostream>
#include <ctime>
#include <map>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

map <string, tm> birthdays;

bool compareByMonthDay(const pair<string, tm>& a, const pair<string, tm>& b) 
{
    // Compare by month first, then by day
    if (a.second.tm_mon != b.second.tm_mon) {
        return a.second.tm_mon < b.second.tm_mon;
    }
    return a.second.tm_mday < b.second.tm_mday;
}

void addBirthday()
{

    string name;
    tm birthday;
    while(true)
    {
        cout << "Enter friends name(enter 'end' to finish): ";
        cin >> name;

        if(name == "end")
            return;
        
        cout << "Enter birthday date in format YYYY/MM/DD: ";
        cin >> get_time(&birthday, "%Y/%m/%d");
        birthdays[name] = birthday;
    }
}


void sortBirthdays(map <string, tm> bdays) {

    vector<pair<string, tm>> birthdayList(bdays.begin(), bdays.end());

    // Sort the vector using the custom comparator
    sort(birthdayList.begin(), birthdayList.end(), compareByMonthDay);

    // Output the sorted birthdays
    cout << "\nUpcoming birthday!\n";
    for (auto& bday : birthdayList)
    {
        cout << bday.first << ": " << bday.second.tm_mon<< " month" << 
            bday.second.tm_mday  << " days until birthday\n";
    }
}


void findNextBirthday()
{
    time_t now = time(nullptr);
    tm* current_time = localtime(&now);
    map <string, tm> next_birthday;
    for (auto& birthday : birthdays)
    {   
        // check today's birthday
        if (birthday.second.tm_mon == current_time->tm_mon && 
            birthday.second.tm_mday == current_time->tm_mday)
        {
            cout <<"\nToday " << birthday.first << " has birthday !\nDon't forget to congratulate!\n";
            continue;
        }

        tm next_date;
        tm date = birthday.second;

        // check if birthday passed
        if (date.tm_mon < current_time ->tm_mon || 
        date.tm_mon == current_time ->tm_mon && date.tm_mday < current_time ->tm_mday)
            continue;

        next_date.tm_mon = date.tm_mon - current_time ->tm_mon;
        next_date.tm_mday= date.tm_mday - current_time ->tm_mday;

        // if day is negative add day from last month
        if (next_date.tm_mday < 0)
        {
            next_date.tm_mon --;
            tm lastMonth = *current_time;
            lastMonth.tm_mon--; 
            mktime(&lastMonth); 
            next_date.tm_mday+= (lastMonth.tm_mday); 
        }
        next_birthday[birthday.first] = next_date;
    }      
        sortBirthdays(next_birthday);
}


int main()
{
    addBirthday();
    findNextBirthday();
}