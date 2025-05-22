/* Продолжение задания №...
Две корпорации хотят разделить сферы влияния, выбрав два разных города для размещения своих штаб-квартир так, чтобы все города, в некоторой округе от штаб-квартиры не были доступны для конкурентов.
Схема автомобильного сообщения задана матрицей смежности в файле. Определить города, достижимые из обоих штаб-квартир через ≤L промежуточных городов. Вывести их в порядке возрастания или -1.
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include "CitiesGraph.h"

using namespace std;

/**
 * @brief Запрашивает у пользователя ввод числа с проверкой на корректность.
 * @param prompt Сообщение для пользователя.
 * @param min Минимальное допустимое значение.
 * @param max Максимальное допустимое значение.
 * @return Введённое число.
 */
int ReadValidInput(const string& prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < min || value > max) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Ошибка ввода. Введите число от " << min << " до " << max << endl;
        }
        else {
            break;
        }
    }
    return value;
}

int main() {
    setlocale(LC_ALL, "");
    // Ввод имени файла
    cout << "Enter file name: ";
    string file_name;
    cin >> file_name;

    ifstream input(file_name);
    if (!input.is_open()) {
        cerr << "Ошибка открытия файла" << endl;
        return 1;
    }

    // Чтение количества городов
    int n = 0;
    input >> n;
    if (n <= 0 || n > 25) {
        cerr << "Некорректное число городов" << endl;
        input.close();
        return 1;
    }

    // Чтение матрицы смежности
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            input >> matrix[i][j];
            if (matrix[i][j] != 0 && matrix[i][j] != 1) {
                cerr << "Некорректное значение в матрице" << endl;
                input.close();
                return 1;
            }
        }
    }
    input.close();

    // Ввод K1, K2 и L с проверкой
    int k1 = ReadValidInput("Введите K1 (1-" + to_string(n) + "): ", 1, n);
    int k2 = ReadValidInput("Введите K2 (1-" + to_string(n) + "): ", 1, n);
    int l = ReadValidInput("Введите L (>=0): ", 0, numeric_limits<int>::max());

    // Получение достижимых городов
    vector<int> reachable1, reachable2;
    try {
        reachable1 = CitiesGraph::GetReachableCities(matrix, k1, l);
        reachable2 = CitiesGraph::GetReachableCities(matrix, k2, l);
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    // Поиск пересечения
    unordered_set<int> set1(reachable1.begin(), reachable1.end());
    vector<int> intersection;
    for (int city : reachable2) {
        if (set1.count(city)) {
            intersection.push_back(city);
        }
    }

    // Вывод результата
    sort(intersection.begin(), intersection.end());
    if (intersection.empty()) {
        cout << -1 << endl;
    }
    else {
        for (int city : intersection) {
            cout << city << ' ';
        }
        cout << endl;
    }

    return 0;
}