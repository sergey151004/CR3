#include "CorporationHQ.h"
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>

CorporationHQ::CorporationHQ(const std::string& fileName, int K1, int K2, int L)
    : K1(K1), K2(K2), L(L) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        exit(1);
    }

    file >> n;
    adjMatrix.resize(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file >> adjMatrix[i][j];
        }
    }
    file.close();
}

std::vector<int> CorporationHQ::BFS(int start) {
    std::vector<bool> visited(n, false);
    std::queue<int> q;
    std::vector<int> reachableCities;

    q.push(start - 1);
    visited[start - 1] = true;
    int level = 0;

    while (!q.empty() && level <= L) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int current = q.front();
            q.pop();
            reachableCities.push_back(current + 1);

            for (int j = 0; j < n; ++j) {
                if (adjMatrix[current][j] && !visited[j]) {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
        ++level;
    }

    return reachableCities;
}

std::vector<int> CorporationHQ::findCommonCities() {
    std::vector<int> reachableFromK1 = BFS(K1);
    std::vector<int> reachableFromK2 = BFS(K2);

    std::vector<int> commonCities;
    std::sort(reachableFromK1.begin(), reachableFromK1.end());
    std::sort(reachableFromK2.begin(), reachableFromK2.end());

    std::set_intersection(reachableFromK1.begin(), reachableFromK1.end(),
                          reachableFromK2.begin(), reachableFromK2.end(),
                          std::back_inserter(commonCities));

    return commonCities;
}
