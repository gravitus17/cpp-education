#include <iostream>
#include <fstream>
#include <limits>
#include <numeric>
#include <cmath>
#include <ctime>
using namespace std;

struct Statement
{
    string name = "Unknown";
    string date;
    double payment = 0;
    string cy = "rub.";
};

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

void list()
{
    ifstream inFile("statement.txt");
    if (!inFile.is_open())
    {
        cerr << "File didn't exist!\n";
        return;
    }
    Statement entry;
    string name;
    string surname;
   
    while (inFile >> name >> surname >> entry.date >> entry.payment >> entry.cy)
    {
        entry.name = name + " " + surname;
        cout << entry.name << " " << entry.date << " " << entry.payment << " " << entry.cy << endl;
    }

    if (inFile.bad())
    {
        cerr << "I/O error while reading from file\n";
    }
    
    inFile.close();
}

void add()
{
    ofstream outFile("statement.txt", ios:: app);
    if(!outFile)
    {
        cerr << "Wrong file!\n";
    }

    Statement entry = {.name = controlName(), .date  =controlDate(), .payment = controlPayment()};

    outFile.setf(ios::showpoint);
    outFile.setf(ios::fixed);
    outFile.precision(2);

    outFile << entry.name << " " << entry.date << " " << 
            entry.payment << " " << entry.cy << endl;
    
    outFile.close();

}

int main()
{
    string user_input;
    while(true)
    {
        cout << "Operation:\n" << "1.'add' - add statement\n" << "2. 'list' - show all statement\n"
            << "3.'exit' - end program\n";
        cin >> user_input;

        if (user_input == "add")
        {
            add();
        }
        else if( user_input == "list")
        {
            list();
        }
        else if (user_input == "exit")
        {
            return 0;
        }
        else
        {
            cerr << "Wrong Input\n";
        }
    }
}