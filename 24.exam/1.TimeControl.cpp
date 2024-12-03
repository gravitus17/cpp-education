#include <iostream>
#include <ctime>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

map <string, double> finished_tasks;
string current_task;
time_t start_time;


void status()
{
    if(!current_task.empty())
    {
        cout << "\ncurrent task: " << current_task << endl;
    }

    for( auto& task : finished_tasks)
    {
        int HH = int(task.second)/3600;
        int MM = (int(task.second) % 3600)/60;
        cout << task.first << ": " << HH << ":" << MM << endl;
    }

}
void endTask()
{
    double end_time =  difftime(time(nullptr), start_time);
    finished_tasks[current_task] = end_time;
    current_task.clear();}

void beginTask()
{
    if (!current_task.empty())
        endTask();
    
    cout << "\nInput your task: ";

    cin.ignore();
    getline(cin, current_task);
    start_time = time(nullptr);

}

int main()
{
    string user_input;
    while(true)
    {
        cout << "\nInput command: " <<"\n1.begin — start a new task" <<
            "\n2.end — finish current task" <<"\n3.status — display all finished task" <<
            "\n4.exit — finish program\n";

        cin >> user_input;

        if (user_input == "begin")
            beginTask();
        else if (user_input == "end")
            endTask();
        else if(user_input == "status")
            status();
        else if (user_input == "exit")
            exit(0);
        else
            cerr << "\nWrong command!\n";
    }
}