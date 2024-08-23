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
    
        if (std::cin.fail() || std::cin.peek() != '\n'|| value < 0)
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

vector<int> remove_vec(vector<int>vec, int remove)
{
    vector<int> new_vec;
    for(int i = 0; i < vec.size(); i++)
    {
        new_vec.push_back(vec[i]);
        if (vec[i] == remove)
            new_vec.pop_back();
    }
    return new_vec;
}

int main()
{
    int N;
    cout << "Enter vector size.\n";
    N = controlInput();

    vector<int> vec(N);

    cout << "Full the vector.\n";
    for (int i = 0; i < N; i++)
        cin >> vec[i];

    int num = 0;
    while(num !=1)
    {
        
        int remove_number;
        cout << "Enter number to remove\n";
        cin >> remove_number;
        vec = remove_vec(vec, remove_number);
        cout << "Would you like to continue ? (1 — exit)\n";
        num = controlInput();
    }

    for (int i = 0; i < vec.size(); i++)

    cout << vec[i] << " ";
}