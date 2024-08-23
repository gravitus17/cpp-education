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

int main()
{
    int N;
    cout << "enter number of price.\n";
    N = controlInput();
    
    vector<float> price(N);
    vector<int> buy;

    cout << "Enter price\n";
    for(int i = 0; i < N; i++)
        cin >> price[i];

    int num = 1;
    do
    {
        int choice = 0;
        cout << "Choose goods\n";
        for( int i = 0; i < N; i++)
            cout << (i+1) << " — " << price[i] << endl;

        cin >> choice;
        if (choice > price.size()|| choice < 1)
            continue;
        else
            buy.push_back(choice-1);
        
        cout << "Continue your purchase ? (1 - yes)\n";
        cin >> num;

    } while (num == 1);
    
    float sum;
    for(int i = 0; i < buy.size(); i++ )
        sum += price[buy[i]];
    
    cout << "Total: " << sum << endl;


}