#include <iostream>
#include <vector>
#include <limits>
#include <numeric>

using namespace std;

int controlInput()
{
    while(true)
    {
        int value; 
        std::cin >> value;
    
        if (std::cin.fail() || std::cin.peek() != '\n'|| value <= 0)
        {
            std::cerr << "Ошибка ввода данных\n";
        
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            return value;
            exit(1);
        }
    }
    return 0;
}

int main()
{
    int result;
    int N;
    cout << "Input desired result:";
    cin >> result;

    cout << "Input vector size: ";
    N = controlInput();
    vector<int> vec(N);

    cout << "full vector:\n";
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N ; j++)
        {
            if (vec[i]+vec[j] == result)
            {
                cout << vec[i] << " + " << vec[j] << " = " << result <<endl;
                break;
            }
        }
        
    }
    

}