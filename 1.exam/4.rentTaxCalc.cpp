#include <iostream>

int main() {
    int totalRent = 4000000;
    int entranceSum = 10;
    int flatPerEntrance = 40;
    int rentPerFlat = totalRent / (entranceSum * flatPerEntrance);

    std::cout << "Приветствуем вас в калькуляторе квартплаты!\n";
    std::cout << "\nВведите сумму, указанную в квитанции: " << totalRent <<"\n";
    std::cout << "Сколько подъездов в вашем доме? " << entranceSum <<"\n"; 
    std::cout << "Сколько квартир в каждом подъезде? " << flatPerEntrance <<"\n"; 
    std::cout << "----Считаем-----\n";
    std::cout << "Каждая квартира должна платить по " << rentPerFlat << " руб.\n";
}

