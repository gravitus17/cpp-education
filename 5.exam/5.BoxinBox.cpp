#include <iostream>
using namespace std;


int main() {
    int a;
    int b;
    int c;
    cout << "Введите размеры первой Коробки\n";
    cin >> a >> b >> c;

    int m;
    int n;
    int k;

    std::cout << "Введите размеры второй коробки:\n";
    std::cin >> m >> n >> k;

    if (a <= m && b <= m  && c<= m|| a <= n && b <= n && c <= n ||  a <= k && b <= k && c <= k )
    {
        std::cout << "Можно";
    }
    else {
        std::cout << "Нельзя";
    }
}