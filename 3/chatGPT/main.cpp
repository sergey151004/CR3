#include "GraphProcessor.h"
#include <iostream>
#include <vector>

int main() {
    GraphProcessor processor;
    std::string filename;
    int k1, k2, l;

    std::cout << "Введите имя файла с матрицей смежности: ";
    std::cin >> filename;

    if (!processor.loadGraphFromFile(filename)) {
        std::cerr << "Ошибка при загрузке графа." << std::endl;
        return 1;
    }

    std::cout << "Введите номер первой штаб-квартиры K1: ";
    if (!(std::cin >> k1) || k1 < 1) {
        std::cerr << "Ошибка: Неверный номер города K1." << std::endl;
        return 1;
    }

    std::cout << "Введите номер второй штаб-квартиры K2: ";
    if (!(std::cin >> k2) || k2 < 1) {
        std::cerr << "Ошибка: Неверный номер города K2." << std::endl;
        return 1;
    }

    std::cout << "Введите максимальное количество промежуточных шагов L: ";
    if (!(std::cin >> l) || l < 0) {
        std::cerr << "Ошибка: Неверное значение шагов L." << std::endl;
        return 1;
    }

    std::vector<int> commonCities = processor.findCommonCities(k1, k2, l);

    if (commonCities.empty()) {
        std::cout << "-1" << std::endl;
    } else {
        for (auto city : commonCities) {
            std::cout << city << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}