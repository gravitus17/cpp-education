#include <iostream>

int main(){
    int productCost = 232;
    int DeliveryCost = 59;
    int sale = 15;
    int totalCost = (productCost + DeliveryCost) - sale;

    std::cout << "====================\n\n";
    std::cout << "Стоимость товара: " << productCost <<"\n";
    std::cout << "Стоимость доставки: " << DeliveryCost << "\n";
    std::cout << "Скидка: " << sale << "\n";
    std::cout << "\n====================\n";
    std::cout << "Итого: " << totalCost << "\n";
    std::cout << "Спасибо за заказ !";

}