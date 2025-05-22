/**
 * @file    CitiesGraph.h
 * @brief   Класс для работы с графом городов и поиска достижимых городов.
 */

#ifndef CITIESGRAPH_H
#define CITIESGRAPH_H

#include <vector>
#include <stdexcept>

class CitiesGraph {
public:
    /**
     * @brief Находит города, достижимые из заданного города через ≤L промежуточных.
     * @param matrix Матрица смежности.
     * @param start_city Стартовый город (1-индексация).
     * @param max_intermediate Максимальное число промежуточных городов.
     * @return Вектор достижимых городов.
     * @throws invalid_argument, out_of_range При некорректных данных.
     */
    static std::vector<int> GetReachableCities(
        const std::vector<std::vector<int>>& matrix,
        int start_city,
        int max_intermediate
    );
};

#endif