/* 
 * CityReachability.cpp
 * 
 * Реализация класса для определения достижимых городов из двух штаб-квартир.
 */

#include "CityReachability.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

CityReachability::CityReachability(int n) 
    : adjacency_matrix_(n, std::vector<bool>(n, false)) {}

bool CityReachability::initializeFromMatrixFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл с матрицей смежности");
    }

    int n;
    if (!(file >> n)) {
        throw std::runtime_error("Некорректный формат файла: отсутствует размер матрицы");
    }

    if (n <= 0 || n > 25) {
        throw std::invalid_argument("Количество городов должно быть от 1 до 25");
    }

    adjacency_matrix_.resize(n, std::vector<bool>(n, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int connection;
            if (!(file >> connection)) {
                throw std::runtime_error("Некорректный формат файла: ошибка при чтении матрицы");
            }
            adjacency_matrix_[i][j] = (connection == 1);
        }
    }

    return true;
}

void CityReachability::validateCityNumber(int city) {
    const int n = adjacency_matrix_.size();
    if (city <= 0 || city > n) {
        throw std::invalid_argument("Номер города должен быть от 1 до " + std::to_string(n));
    }
}

std::vector<int> CityReachability::findCommonlyReachableCities(int k1, int k2, int l) {
    validateCityNumber(k1);
    validateCityNumber(k2);

    const int n = adjacency_matrix_.size();
    k1--; k2--;  // Переводим в нулевой индекс

    std::vector<int> reachable_from_k1 = findReachableCities(k1, l);
    std::vector<int> reachable_from_k2 = findReachableCities(k2, l);

    std::vector<int> common_cities;
    for (int city : reachable_from_k1) {
        if (std::find(reachable_from_k2.begin(), reachable_from_k2.end(), city) != 
            reachable_from_k2.end()) {
            common_cities.push_back(city + 1);  // Возвращаем в формате 1-based index
        }
    }

    return common_cities;
}

std::vector<int> CityReachability::findReachableCities(int start, int max_intermediate) {
    const int n = adjacency_matrix_.size();
    std::vector<bool> visited(n, false);
    std::vector<int> distances(n, -1);
    std::queue<int> bfs_queue;

    visited[start] = true;
    distances[start] = 0;
    bfs_queue.push(start);

    while (!bfs_queue.empty() && distances[start] <= max_intermediate) {
        int current_city = bfs_queue.front();
        bfs_queue.pop();

        for (int next_city = 0; next_city < n; ++next_city) {
            if (adjacency_matrix_[current_city][next_city] && !visited[next_city]) {
                visited[next_city] = true;
                distances[next_city] = distances[current_city] + 1;
                bfs_queue.push(next_city);
            }
        }
    }

    std::vector<int> reachable_cities;
    for (int i = 0; i < n; ++i) {
        if (visited[i] && distances[i] <= max_intermediate) {
            reachable_cities.push_back(i + 1);  // Возвращаем в формате 1-based index
        }
    }

    return reachable_cities;
}