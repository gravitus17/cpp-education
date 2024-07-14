#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int cashOut;
    int typeOfNote[6] = {100, 200, 500, 1000, 2000, 5000};

    cout << "Введите сумму снятия наличными: \nСумма не должна превышать 150 000 руб.\n";
    cin >> cashOut;

    if (cashOut > 150'000)
    {
        cout << "Невозможно выдать наличными больше 150 000 руб.";
    }
    else if (cashOut% 100 != 0)
    {
        cout << "Невозможно выдать " << cashOut << " руб. \nСумма должна быть кратна 100 руб.\n";
    }
    else
    {
        vector<vector<int>> cashWithDraw;
        do
        {
            for (int i = 5; i >=0; i--)
            {
                if (cashOut/typeOfNote[i] == 0)
                {
                    continue;
                }
                else
                {
                    vector<int> bankNoteNum = {(cashOut/typeOfNote[i]),typeOfNote[i]};
                    cashWithDraw.push_back(bankNoteNum);
                    cashOut =cashOut - typeOfNote[i]*(cashOut/typeOfNote[i]);
                }

            }
        } while(cashOut != 0);
        cout << "Происходит выдача купюр.\n";
        cout << "--------------------\n";

        for (int i = 0; i < cashWithDraw.size(); i++)
        {
            cout << "Купюр номиналом " << cashWithDraw[i][1] << " — " << cashWithDraw[i][0] << " шт.\n";
        }
    }
}