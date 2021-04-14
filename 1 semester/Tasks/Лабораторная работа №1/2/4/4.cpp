
#include <iostream>

int main()
{
    int x = 0;
    int y = 0;
    std::cout << "Enter x:\n";
    std::cin >> x;
    std::cout << "Enter y:\n";
    std::cin >> y;
    double s = 0;
    s = (3 + x * x - y * y * y) * (x + 3) * (x + 3) / (x - y * y);
    std::cout << s;
    return 0;
    
}


