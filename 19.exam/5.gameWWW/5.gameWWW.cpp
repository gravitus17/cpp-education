#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <numeric>

using namespace std;

const int TOTAL_SECTORS = 13;
const int WINNING_SCORE = 6;
const int BUFFER_SIZE = 1024;
const string FILE_PATH = "/home/greg/cpp-education/19.exam/5.gameWWW/sectors/sector_";

vector<int> Played_sector(13);
int playerScore = 0;
int viewerScore = 0;

int controlInput()
{
    while(true)
    {
        int value; 
        std::cin >> value;
    
        if (std::cin.fail() || std::cin.peek() != '\n'|| value < 0 || value >13)
        {
            std::cerr << "Ошибка ввода данных\n";
        
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            return value;
        }
    }
    return 0;

}

void FirstCap(string &str)
{
    for (int x = 0; x < str.length(); x++)
    {
        // If it's the first character of the string or after a space, capitalize it
        if (x == 0 || str[x - 1] == ' ')
        {
            str[x] = toupper(str[x]); 
        }
    }
}
 
void currentSector(int& currentSector)
{
    int offset;
    int i = 0;
    cout << "Input  sector offset:\n ";
    offset = controlInput();
    currentSector +=  offset;

    if (currentSector > TOTAL_SECTORS) 
        {
            currentSector = currentSector%TOTAL_SECTORS;
        }

    //check played_sector
    while(i != sizeof(Played_sector))
    {
        if ( Played_sector[i] == currentSector)
            {
                currentSector++;
                i = 0;
                if (currentSector >13)
                    currentSector =1;       
            }
        else
            i++;    
    }

    Played_sector.push_back(currentSector); 
    cout << "Current Sector: " << currentSector << endl;


}

void askQuestion(int &currentSector)
{
    ifstream questionfile(FILE_PATH + to_string(currentSector)+".txt");
    vector<char> buffer(BUFFER_SIZE);

    if(!questionfile.is_open())
        cout << "Wrong file!\n";
    else
    {
        while(!questionfile.read(buffer.data(),BUFFER_SIZE ))
        {
            streamsize bytes_read = questionfile.gcount();
            if ( bytes_read <= 0)
                break;
        
            cout.write(buffer.data(), bytes_read);
        }
        cout << endl;
    } 
    questionfile.close();
}

void checkAnswer(int &currentSector)
{
    int sector_num;
    string player_answer;
    string correct_answer;
    ifstream answerFile("/home/greg/cpp-education/19.exam/5.gameWWW/sectors/answer.txt");

    cout << "Input your answer: ";
    cin.ignore();
    getline(cin, player_answer);

    // capitalize first letter
    FirstCap(player_answer);

    //get the answer from file
    while(!answerFile.eof())
    {   
        string first_part;
        answerFile >> sector_num; 
        getline(answerFile, first_part);
        
        if (sector_num == currentSector)
        {
            correct_answer = first_part;
            break;
        }
    }
    if (correct_answer == player_answer)
    {
        cout << "Players get point!\n";
        playerScore++;
    }
    else
    {
        cout << "Viewers get point!\n";
        viewerScore++;
    }
    answerFile.close();
}

void declareWinner()
{
    if (playerScore >= 6)
     cout << "CONGRATULATION!\nThe player's team WIN! \n";
    else
         cout << "CONGRATULATION!\nThe viewer's team WIN! \n";

}

int main()
{
  
    int Sector = 0;

    while(playerScore < WINNING_SCORE || viewerScore < WINNING_SCORE)
    {
        cout << "Player Score: " << playerScore << 
            "\nViewer score: " << viewerScore << endl;

        currentSector(Sector);
        askQuestion(Sector);
        checkAnswer(Sector);
    }
    void declareWinner();
}