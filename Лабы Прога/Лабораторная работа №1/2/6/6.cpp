
#include <iostream>

int main()
{
    double a0 = 0;
    std::cout << "Enter a:\n";
    std::cin >> a0;
    double a = 0;
    double temp = 0;
    double temp1 = 0;

    //а                
    a = a0;
    a = a * a;
    a = a * a;
    std::cout << "a^4 = " << a << "\n";

    //б
    a = a0;
    temp = a * a;
    a = temp * temp;
    a = a * temp;
    std::cout << "a^6 = " << a << "\n";

    //в
    a = a0;
    temp = a * a;
    a = temp * temp;
    a = a * temp;
    a = a * a0;
    std::cout << "a^7 = " << a << "\n";

    //г
    a = a0;
    a = a * a;
    a = a * a;
    a = a * a;
    std::cout << "a^8 = " << a << "\n";

    //д
    a = a0;
    a = a * a;
    a = a * a;
    a = a * a;
    a = a * a0;
    std::cout << "a^9 = " << a << "\n";

    //е
    a = a0;
    a = a * a;
    a = a * a;
    a = a * a;
    a = a * temp;
    std::cout << "a^10 = " << a << "\n";

    //ж
    a = a0;
    a = a * a;
    temp = a * a;
    a = temp * temp;
    a = a * temp;
    a = a * a0;
    std::cout << "a^13 = " << a << "\n";

    //з
    









    return 0;
}


