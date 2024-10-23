#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>

using namespace std;

const vector<string>  fish_spices = {"Carp", "Catfish", "Roach", "Chub", "Perch", "Salmon", "Zander", "Catfish"};

void CreateFishPull()
{
    srand(time(nullptr));
    int rand_num;
    ofstream river("fish.txt", ios::out | ios::trunc);
    int generate_range_num = rand()% 51 +10;
    for( int i = 0; i < generate_range_num; i ++)
    {
        rand_num = rand() % (fish_spices.size());
        river << fish_spices[rand_num]<< endl;
    }
    river.close();

}

string spiceChoice()
{
    int num;
    string fish_choice;
    while (true)
    {
        for(int i = 0; i < fish_spices.size(); i++)
        {
            cout << i+1 << ". " << fish_spices[i] << endl;
        }
        cout << "Enter the number of fish: ";
        cin >> num;

        if (num > fish_spices.size() || num < 1)
        {
            cout << "Wrong input!\n";
            continue;
        }
        else
        {
            num--;
            fish_choice =  fish_spices[num];
            cout << "Your choice: " << fish_choice << endl;
            return fish_choice;
        }
    }
}

void fishing()
{
    ofstream basket("basket.txt",ios::app);
    ifstream river("fish.txt");
    string spice = spiceChoice();
    string catch_fish;


    int counter = 0;

    while(!river.eof())
    {
        river >> catch_fish;
        if (spice == catch_fish)
        {
            basket << catch_fish << endl;
            counter++;
        }
    }
    river.close();
    cout << "Congratulation!\n" <<" You catch " << counter << " " << spice << endl;
    
   
    basket.close();

}
int main()
{


    CreateFishPull();
    fishing();


}