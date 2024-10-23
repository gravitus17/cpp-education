#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

const int TICKET_DENOMINATION[6] = {100, 200, 500, 1000, 2000, 5000};
const string PATH = "/home/greg/cpp-education/20.exam/4.ATMsimulator/ATM.bin";

int money[1000]  = {0};

void AtmStatus()

{
    ifstream atm_in;
    atm_in.open(PATH, ios::binary);

    if (!atm_in.is_open())
    {
        cout << "The ATM is empty.\n";
        ofstream atm_out(PATH, ios::binary);
        atm_out.write((char *)&money, sizeof(money));
        atm_out.close();
    }
    else
    {
        atm_in.read((char *)&money, sizeof(money));
        int amount_ticket[6] = {0};
        int total_sum = 0;
        for (int i = 0; i < 6; i++)
        {
            for (int g = 0; g < 1000; g++)
            {
                if (money[g] == TICKET_DENOMINATION[i])
                {
                    amount_ticket[i] += 1;
                    total_sum += TICKET_DENOMINATION[i];
                }
            }
        }
        int count100 = 0;
        for ( int i : money )
        {
            if( i == 100)
                count100++;
        }
        cout << " count 100 -" << count100 << endl;
        cout << "Amount banknote:\n";
        for (int i = 0; i < 6; i++)
        {
            cout << TICKET_DENOMINATION[i] << " - " << amount_ticket[i] << endl;
        }
        cout << "\nAvailable Amount: " << total_sum << endl;
    }
    atm_in.close();
}
void Withdraw()
{
    // ifstream atm_in("ATM.bin", ios::binary);
    ofstream atm_out(PATH, ios::binary);
    int amount;
    cout << "Amount: ";
    cin >> amount;

    if ((amount % 100) != 0)
    {
        cerr << "Invalid Amount" << amount << endl;
        return;
    }

    int banknote;
    int amount_to = amount;

    for (int i = 5; i >= 0; i--)
    {
        banknote = TICKET_DENOMINATION[i];
        for (int g = 0; g < 1000; g++)
        {
            if (money[g] == banknote && amount_to >= banknote)
            {
                money[g] = 0;
                amount_to -= banknote;
                if (amount_to == 0)
                {
                    cout << "Amount withdrawn: " << amount << endl;

                    atm_out.write((char *)&money, sizeof(money));
                    atm_out.close();
                    return;
                }
            }
        }
    }
    cerr << "Not enough banknote!" << endl;
}

void Replenishment()
{
    int num;
    ifstream atm_in(PATH, ios::binary);
    atm_in.read((char*) &money, sizeof(money));
    atm_in.close();

    for (int i = 0; i < sizeof(money); i++)
    {
        if (money[i] == 0)
        {
            num = rand() % 6;
            money[i] = TICKET_DENOMINATION[num];
        }
    }
    ofstream atm_out(PATH, ios::binary);
    atm_out.write((char *)&money, sizeof(money));
    atm_out.close();
}

int ATM()
{
    char operation;
    while (true)
    {
        AtmStatus();

        cout << "\noperation type: \n"
             << "'+' replenishment operation\n"
             << "'-' withdraw operation\n"
             << "exit - any symbol\n";

        cout << "\nEnter Operation: ";
        cin >> operation;

        if (operation == '+')
        {
            Replenishment();
        }
        else if (operation == '-')
        {
            Withdraw();
        }
        else
        {
            return 1;
        }
    }
}

int main()
{
    srand(time(nullptr));
    ATM();
}