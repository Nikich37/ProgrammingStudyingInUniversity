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
    cout << "Введите размер массива: ";
    cin >> n;

    vector <char> vec(n);

    cout << "Введите " << n << " элементов для заполнения массива: " << endl;

    for (int i = 0; i < n; i++) {
        cin >> vec[i]; 
    }

    BubbleSort(vec);

    

    cout << "Массив в отсортированном виде: ";

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " "; // выводим элементы массива
    }
    system("pause");
    return 0;
}