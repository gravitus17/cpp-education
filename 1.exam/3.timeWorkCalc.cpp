#include <iostream>

int main() {
    int workShift = 480;
    int clientMakeOrder = 2;
    int workerCollectOrder = 4;
    int maxClientperShift = workShift / (clientMakeOrder+workerCollectOrder);

    std::cout << "Эта программа рассчитает, сколько клиентов успеет обслужить кассир за смену.\n";
    std::cout << "Введите длительность смены в минутах: " << workShift << "\n";
    std::cout << "Сколько минут клиент делает заказ? " << clientMakeOrder << "\n";
    std::cout << "Сколько минут кассир собирает заказ? " << workerCollectOrder << "\n";
    std::cout << "-----Считаем----- \n";
    std::cout << "За смену длиной " << workShift << " минут кассир успеет обслужить " << maxClientperShift << ".\n";
}