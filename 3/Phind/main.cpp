/* 
 * main.cpp
 * 
 * Программа для определения городов, достижимых из двух штаб-квартир с ограничением на количество промежуточных городов.
 */

#include <iostream>
#include <vector>
#include "CityReachability.h"

int main() {
    try {
        CityReachability reachability(0);  // Создаем объект без начального размера
        
        std::cout << "Введите имя файла с матрицей смежности: ";
        std::string filename;
        std::cin >> filename;

        reachability.initializeFromMatrixFile(filename);

        std::cout << "Введите номер первой штаб-квартиры (K1): ";
        int k1;
        std::cin >> k1;

        std::cout << "Введите номер второй штаб-квартиры (K2): ";
        int k2;
        std::cin >> k2;

        std::cout << "Введите максимальное количество промежуточных городов (L): ";
        int l;
        std::cin >> l;

        std::vector<int> reachable_cities = reachability.findCommonlyReachableCities(k1, k2, l);

        if (reachable_cities.empty()) {
            std::cout << "-1\n";
        } else {
            for (int city : reachable_cities) {
                std::cout << city << " ";
            }
            std::cout << "\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";
        return 1;
    }

    return 0;
}