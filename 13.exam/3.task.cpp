#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> db(20);
    int num;
    int pos = 0;

    cout << "input number: ";
    cin >> num;

    while(num != -2)
    {
        if(num == -1)
        {
            for(int i = pos; i <db.size(); i++)
                cout << db[i] << " ";

            for(int i = 0; i < pos; i++)
                cout << db[i] << " "; 
        }
        else
        {
            db[pos] = num;
            pos++;
            if (pos == 21)
                pos = 0;
        }
        cin >> num;
    }
}