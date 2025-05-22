#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>
#include "CorporationHQ.h"

int main() {
    std::string fileName;
    int K1, K2, L;

    std::cout << "Enter the file name: ";
    std::cin >> fileName;

    std::cout << "Enter the first candidate city (K1): ";
    std::cin >> K1;

    std::cout << "Enter the second candidate city (K2): ";
    std::cin >> K2;

    std::cout << "Enter the maximum number of intermediate cities (L): ";
    std::cin >> L;

    CorporationHQ corpHQ(fileName, K1, K2, L);
    std::vector<int> result = corpHQ.findCommonCities();

    if (result.empty()) {
        std::cout << "-1" << std::endl;
    } else {
        for (int city : result) {
            std::cout << city << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
