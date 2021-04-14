
#include <iostream>

int main()
{
    int m = 0;
    std::cout << "Enter m:\n";
    std::cin >> m;
    int x = (m / 3600) % 24;
    int y = (m % 3600) / 60;
    std::cout << "Time is " << x << ":" << y;
    return 0;
}


