#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void BubbleSort(vector<T>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size() - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                auto b = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = b;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");

    int n;
    cout << "������� ������ �������: ";
    cin >> n;

    vector <char> vec(n);

    cout << "������� " << n << " ��������� ��� ���������� �������: " << endl;

    for (int i = 0; i < n; i++) {
        cin >> vec[i]; 
    }

    BubbleSort(vec);

    

    cout << "������ � ��������������� ����: ";

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " "; // ������� �������� �������
    }
    system("pause");
    return 0;
}