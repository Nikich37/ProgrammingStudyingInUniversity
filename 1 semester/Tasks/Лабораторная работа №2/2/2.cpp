#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int count;
    double a, b;
    cout << "������� ����� �: ";
    cin >> a;
    cout << "������� ����� �: ";
    cin >> b;
    cout << "��������: 1-��������; 2-���������; 3-���������; 4-�������: ";
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
        cout << "������������ ����" << endl;
    }
    system("pause");
    return 0;
}