#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main()
{
    string name;
    string surname;
    int num;
    string date;
    int max_sum = 0;
    string max_name;
    int sum;
    ifstream data("statement.txt");

    while(!data.eof())
    {
        data >> name >> surname >> num >> date;
        name += " "+ surname;
        if (num > max_sum)
        {
            max_name = name;
            max_sum = num;
        }
        sum += num;
    }
    data.close();
    cout << "Total Sum: " << sum << endl;
    cout << "Max pay:\n" << max_name << " " << max_sum << endl;
}