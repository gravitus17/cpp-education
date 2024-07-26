#include <iostream>
#include <cmath>
#include <limits>
#include <numeric>

using namespace std;

float controlInput()
{
    while(true)
    {
        float value; 
        std::cin >> value;
    
        if (std::cin.fail() || std::cin.peek() != '\n'|| value <= 0)
        {
            std::cerr << "Ошибка ввода данных\n";
        
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            std::cout << value << '\n';
            return value;
            exit(1);
        }
    }
    return 0;
}

int main()
{
    cout << "Введите здоровье Орка: ";
    float orcHealth = controlInput();
    float orcResist;
    do
    {
        cout << "Введите сопротивляемость Орка в процента(1 — 100%): ";
        orcResist = controlInput();
        if (orcResist >100)
        {
            cout << "сопротивляемость не может быть выше 100%\n";
            continue;
        }
        break;
    }while(true);

    while(orcHealth > 0)
    {
        float orcDamaged;
        cout << "Введите урон: ";
        float playerDamage = controlInput();
        if(orcResist == 100)
        {
            std::string playerChoice;
            orcDamaged =0;
            cout << "Урон " << playerDamage << ", сопротивляемость " 
                << orcResist/100 << ", по орку будет нанесено " << orcDamaged << " урона.\n";
            do{
                
                cout << "Этот Орк слишком силен! Авантюрист тебе надо отступить!\n";
                cout << "Хотите отступить? у/n?\n";
                cin >> playerChoice;
            
            
                if (playerChoice == "y")
                {
                    cout << "Вы успешно убежали!\n";
                    exit(1);
                }
                else if(playerChoice == "n")
                {
                    cout << "Бой продолжается!\n";
                    break;
                }
                else
                    continue;
            } while (true);    
        }
        else
        {
             orcDamaged = (playerDamage / 100 * orcResist);
            orcHealth -= orcDamaged;
            cout << "Урон " << playerDamage << ", сопротивляемость " 
                << orcResist/100 << ", по орку будет нанесено " << orcDamaged << " урона.\n";
        }  
    }

    cout << "Поздравляем! Вы прошли игру (грустная музыка).\n";
}