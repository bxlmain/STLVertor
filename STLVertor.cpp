#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    // Открываем файл для чтения
    ifstream file("input.txt");

    // Проверяем, что файл успешно открылся
    if (!file.is_open()) {
        cerr << "Unable to open file." << endl;
        return 1;
    }

    vector<int> vec;
    int num;

    // Читаем числа из файла в вектор
    while (file >> num) {
        vec.push_back(num);
    }

    // Реверсируем последовательность элементов вектора
    reverse(vec.begin(), vec.end());

    // Находим минимальный элемент
    int min_element = *std::min_element(vec.begin(), vec.end());

    // Удаляем из вектора все четные элементы
    vec.erase(remove_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }), vec.end());

    // Сортируем вектор по убыванию
    sort(vec.rbegin(), vec.rend());

    // Вставляем произвольный элемент в вектор, не нарушая сортировку
    int new_element = 50;
    vec.insert(upper_bound(vec.begin(), vec.end(), new_element, greater<int>()), new_element);

    // Определяем индекс заданного элемента
    int element_to_find = 50;
    auto it = find(vec.begin(), vec.end(), element_to_find);
    int index = (it != vec.end()) ? distance(vec.begin(), it) : -1;

    // Выводим результаты
    cout << "Reversed vector: ";
    for (int x : vec) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Min element: " << min_element << endl;

    cout << "Vector without even elements: ";
    for (int x : vec) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Sorted vector in descending order: ";
    for (int x : vec) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Element " << new_element << " inserted at index " << index << endl;

    file.close();

    return 0;
}