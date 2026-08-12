/*
Арифметическая прогрессия.
Программа должна работать для всех "n ≤ 4000000000"
*/

#include <iostream>

int main() {
    unsigned long long n;
    std::cin >> n;
    std::cout << n * (n + 1) / 2 << "\n";
}