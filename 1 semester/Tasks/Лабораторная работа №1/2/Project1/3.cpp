#include <iostream>

int main()
{
    int x = 0;
    int y = 0;
    std::cout << "Enter x:\n";
    std::cin >> x;
    std::cout << "Enter y:\n";
    std::cin >> y;
    int z = 0;
    z = x;
    x = y;
    y = z;
    std::cout << "x = " << x << "\n";
    std::cout << "y = " << y << "\n";
    return 0;



}