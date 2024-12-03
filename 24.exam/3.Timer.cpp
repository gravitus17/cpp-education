#include <iostream>
#include <iomanip>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

void displayTimeRemaining(int minutes, int seconds) {
    // Display the remaining time in MM:SS format
    cout << "\r" << setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds << flush;
}

int main() {
    int minutes, seconds;

    cout << "Enter the countdown time (MM:SS): ";
    char colon;
    cin >> minutes >> colon >> seconds;

    int totalTime = minutes * 60 + seconds;

    while (totalTime > 0) {
        int remainingMinutes = totalTime / 60;
        int remainingSeconds = totalTime % 60;

        // Display the time remaining
        displayTimeRemaining(remainingMinutes, remainingSeconds);

        // Decrease the total time by one second
        this_thread::sleep_for(chrono::seconds(1));
        --totalTime;
    }

    cout << "\nDING! DING! DING!" << endl;
}