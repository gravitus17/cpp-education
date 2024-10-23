#include <iostream>
#include <fstream>
#include <limits>
#include <numeric>
#include <cmath>
#include <ctime>

using namespace std;

int controlNum()
{
    while(true)
    {
        int value; 
        std::cin >> value;
    
        if (std::cin.fail() || std::cin.peek() != '\n'|| value <0)
        {
            std::cerr << "Ошибка ввода данных\n";
        
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            return value;
        }
    }
    return 0;
}

string controlName()
{
    while(true)
    {
        
        string value; 
        cin.ignore();

        cout << "Enter name: ";
        getline(cin, value);

        bool err = false;

        if (value.length() < 5)
            err = true;

        for (int i = 0; i < value.length(); i++)
        {
            if (err)
                break;

            char c = value[i];
            // Check if the character is not letter or dash for double surname
            if (!islower(c) && !isupper(c) && 
                    c != '-' && !isspace(c))
            {
                err = true;
                break;
            }
            // Check if first letter of word is upper or upper in the word
            else if (isupper(c) && i != 0 && value[i-1] != ' ' &&
                    value[i-1] != '-' )
            {
                err = true;
                break;
            }
            else if (islower(c) && (i == 0 || value[i-1] == ' ' ||
                    value[i-1] == '-'))
            {
                err = true;
                break;
            }
            
        }
        if (err) 
        {
            std::cerr << "Ошибка ввода данных\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else
        {
            return value;
        }
    }
}

double controlPayment()
{

    while(true)
    {
        double value; 
        cout << "Enter payment: ";
        std::cin >> value;
    
        if (std::cin.fail() || std::cin.peek() != '\n'|| value < 0)
        {
            std::cerr << "Ошибка ввода данных\n";
        
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            return value;
        }
    }
    return 0;
}

string controlDate()
{

    while(true)
    {
        string value; 
        cout << "Enter date (format DD.MM.YYYY): ";
        cin >> value;

        bool err = false;
        if (value.length() != 10)
            err = true;

        for (int i = 0; i < value.length(); i++) 
        {
            if (err)
                break;
            // Check correct date format
            if (!isdigit(value[i]) && value[i] != '.' )
            {
                err = true;
                break;
            }
            else if ( value[i] == '.' && (i != 2 && i != 5))
            {
                err = true;
                break;
            }
        }
        
        // check correct data
        if(!err){
            int day = stoi(value.substr(0,2));
            int month =  stoi(value.substr(3,2));
            int year = stoi(value.substr(6,4));
            time_t now = time(nullptr);
            tm* date_time = localtime(&now);
            int current_year = 1900 + date_time->tm_year;

            if ( day > 31 || day < 0||
                month < 0 || month >12 ||
                year < 1900 || year > (current_year-18) )
            {    
                err = true;
            }
            else if ( month == 4 || month == 6|| month == 9 || month == 11  && day == 31)
            {
                err = true;
            }
            if ( month == 2)
            {
                if (day > 29)
                    err = true;
                if (!((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && day == 29)
                    err = true;
            }
        }    

        if (err) 
        {
            std::cerr << "Ошибка ввода данных\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            return value;
        }
    }

}
int main()
{
    string name;
    double payment;
    string date;
    int statement_number;

    ofstream outFile("statement.txt");
    if(!outFile)
    {
        cerr << "Error opening file!\n";
        return 1;
    }

  
    outFile.setf(ios::showpoint);
    outFile.setf(ios::fixed);
    outFile.precision(2);

    cout << "Enter number of statements: ";
    statement_number = controlNum();

    

    for (int i = 0; i < statement_number; i++)
    {
        
        name = controlName();
        payment = controlPayment();
        date = controlDate();

        outFile.width(5);
        outFile << name;
        outFile.width(20);
        outFile << payment;
        outFile.width(25);
        outFile << date << endl;
    }

    outFile.close();
}