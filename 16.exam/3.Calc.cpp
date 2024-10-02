#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string buffer;

    cout << "Input operation: ";
    cin >> buffer;
    stringstream buffer_stream(buffer);
    double a;
    double b;
    char operation;
    buffer_stream >> a >> operation >> b;
    
    double result;

    switch (operation) {  
    case '+':  result = a+b;

    case '-': 
        result = a-b;
        break;
    case '*': 
        result = a*b;
        break;
    case '/':  
        result = a/b;
        break;
    default: throw std::runtime_error("No such operator");
    }

    cout << a << " " << operation << " "<< b << " = "<< result << endl;
    
}