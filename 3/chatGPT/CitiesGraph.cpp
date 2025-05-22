#include "GraphProcessor.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <stdexcept>

bool GraphProcessor::loadGraphFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл " << filename << std::endl;
        return false;
    }

    file >> numCities_;
    if (numCities_ <= 0 || numCities_ > 25) {
        std::cerr << "Ошибка: Неверное количество городов (" << numCities_ << "). Допустимо от 1 до 25." << std::endl;
        return false;
    }

    adjacencyMatrix_.resize(numCities_, std::vector<int>(numCities_, 0));

    for (int i = 0; i < numCities_; ++i) {
        for (int j = 0; j < numCities_; ++j) {
            if (!(file >> adjacencyMatrix_[i][j])) {
                std::cerr << "Ошибка: Неверный формат данных в матрице смежности." << std::endl;
                return false;
            }
            if (adjacencyMatrix_[i][j] != 0 && adjacencyMatrix_[i][j] != 1) {
                std::cerr << "Ошибка: Неверное значение в матрице смежности: " << adjacencyMatrix_[i][j] << std::endl;
                return false;
            }
        }
    }

    file.close();
    return true;
}

std::vector<int> GraphProcessor::getReachableCities(int startCity, int maxSteps) const {
    if (!isValidCity(startCity)) {
        std::cerr << "Ошибка: Неверный стартовый город: " << startCity << std::endl;
        return {};
    }

    if (maxSteps < 0) {
        std::cerr << "Ошибка: Неверное максимальное количество шагов: " << maxSteps << std::endl;
        return {};
    }

    std::vector<bool> visited(numCities_, false);
    std::vector<int> result;
    std::queue<std::pair<int, int>> q; // {город, шаг}
    q.push({startCity - 1, 0}); // переводим в 0-based
    visited[startCity - 1] = true;

    while (!q.empty()) {
        auto [current, steps] = q.front(); q.pop();

        if (steps > maxSteps) continue;

        result.push_back(current + 1); // 0-based -> 1-based

        for (int neighbor = 0; neighbor < numCities_; ++neighbor) {
            if (adjacencyMatrix_[current][neighbor] == 1 && !visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, steps + 1});
            }
        }
    }

    return result;
}

std::vector<int> GraphProcessor::findCommonCities(int k1, int k2, int l) const {
    auto cities1 = getReachableCities(k1, l);
    auto cities2 = getReachableCities(k2, l);

    std::vector<int> common;
    size_t i = 0, j = 0;

    while (i < cities1.size() && j < cities2.size()) {
        if (cities1[i] == cities2[j]) {
            common.push_back(cities1[i]);
            ++i;
            ++j;
        } else if (cities1[i] < cities2[j]) {
            ++i;
        } else {
            ++j;
        }
    }

    return common;
}

bool GraphProcessor::isValidCity(int city) const {
    return city >= 1 && city <= numCities_;
}