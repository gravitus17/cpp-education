#include <iostream>
#include <map>
#include <string>
#include <numeric>
#include <limits>

using namespace std;

multimap <string, int> registry;

string controlInput()
{
    while(true)
    {
        string value; 
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cerr << "error input\n";
        
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

void add()
{
    string family;
    cout << "enter family name:";
    family = controlInput();
    cout << endl;
    
    int id;
    if (registry.empty())
        id = 0;
    else
    {
        auto lastpair = prev(registry.end());
        id = lastpair -> second;
    }   
    pair <string, int> patient(family, id+1);
    registry.insert(patient);
}
void next()
{
    for( auto& family : registry)
    {
        cout << family.first << endl;
    }
}
int main()
{
    string user_input;
    while(true)
    {
        cout << "enter command:" << "\n1.add - add a family" 
            <<"\n2.next - show all family" <<"\n3.exit - end program\n";

        user_input = controlInput();
        if (user_input == "add")    
        {
            add();
        }
        else if(user_input == "next")
            next();
        else if(user_input == "exit")
            break;
        else
            cerr << " Wrong command!\n";
    }
}