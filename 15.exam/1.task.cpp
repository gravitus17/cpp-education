#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

int controlInput()
{
    while(true)
    {
        int value; 
        std::cin >> value;
    
        if (std::cin.fail() || std::cin.peek() != '\n'|| value <=0)
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
    
    int N;
    cout<< "input size of vector:";
    N = controlInput();
    vector<int> vec(N);
    cout << "full vector:";
    for(int i = 0; i < N; i++)
    {    
        cin >> vec[i];
    }

    int max = 0;
    int max_ind = 0;
    int index_A;
    int index_B;
    for (int i = 0; i < N; i++)
    {
        max = vec[i];
        for (int j = i; j < N; j++)
        {
            max +=vec[j];
            if (max_ind < max)
                {
                    max_ind = max;
                    index_A = i;
                    index_B = j;
                }      
        } 
    }
    
    cout << "Max sum of number between index " << index_A << " and " << index_B << endl;
}