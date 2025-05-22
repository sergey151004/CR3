/**
 * @file    CitiesGraph.cpp
 * @brief   Реализация методов для работы с графом городов.
 */

#include "CitiesGraph.h"
#include <queue>
#include <unordered_set>
#include <stdexcept>

using namespace std;

vector<int> CitiesGraph::GetReachableCities(
    const vector<vector<int>>& matrix,
    int start_city,
    int max_intermediate
) {
    if (matrix.empty()) {
        throw invalid_argument("Пустая матрица");
    }
    const int n = static_cast<int>(matrix.size()); // Явное преобразование типа
    if (start_city < 1 || start_city > n) {
        throw out_of_range("Неверный номер города");
    }
    if (max_intermediate < 0) {
        throw invalid_argument("L должно быть >= 0"); // Заменяем ≥ на >=
    }

    vector<bool> visited(n, false);
    queue<pair<int, int>> q;
    unordered_set<int> reachable;

    const int start_idx = start_city - 1;
    q.push(make_pair(start_idx, max_intermediate + 1)); // Явное создание пары
    visited[start_idx] = true;

    while (!q.empty()) {
        // Заменяем структурированные привязки на явное обращение к полям
        const auto& current_pair = q.front();
        int current = current_pair.first;
        int steps = current_pair.second;
        q.pop();

        reachable.insert(current + 1);

        if (steps > 0) {
            for (int next = 0; next < n; ++next) {
                if (matrix[current][next] == 1 && !visited[next]) {
                    visited[next] = true;
                    q.push(make_pair(next, steps - 1)); // Явное создание пары
                }
            }
        }
    }

    return vector<int>(reachable.begin(), reachable.end());
}