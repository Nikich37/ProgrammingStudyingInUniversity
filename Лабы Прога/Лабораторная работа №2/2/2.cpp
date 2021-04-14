#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int count;
    double a, b;
    cout << "Введите число А: ";
    cin >> a;
    cout << "Введите число В: ";
    cin >> b;
    cout << "Выберите: 1-сложение; 2-вычитание; 3-умножение; 4-деление: ";
    cin >> count;
    switch (count)
    {
    case 1:
    {
        cout << a << " + " << b << " = " << a + b << endl;
        break;
    }
    case 2:
    {
        cout << a << " - " << b << " = " << a - b << endl;
        break;
    }
    case 3:
    {
        cout << a << " * " << b << " = " << a * b << endl;
        break;
    }
    case 4:
    {
        cout << a << " / " << b << " = " << a / b << endl;
        break;
    }
    default:
        cout << "Неправильный ввод" << endl;
    }
    system("pause");
    return 0;
}