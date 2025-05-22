#ifndef CORPORATIONHQ_H
#define CORPORATIONHQ_H

#include <vector>
#include <string>

/**
 * @class CorporationHQ
 * @brief Class to find common cities reachable from two headquarters within a given limit of intermediate cities.
 */
class CorporationHQ {
public:
    /**
     * @brief Constructor for CorporationHQ.
     * @param fileName The name of the file containing the adjacency matrix.
     * @param K1 The first candidate city for the headquarters.
     * @param K2 The second candidate city for the headquarters.
     * @param L The maximum number of intermediate cities.
     */
    CorporationHQ(const std::string& fileName, int K1, int K2, int L);

    /**
     * @brief Finds the common cities reachable from both headquarters.
     * @return A vector of integers representing the common cities.
     */
    std::vector<int> findCommonCities();

private:
    int n; /**< Number of cities. */
    std::vector<std::vector<int>> adjMatrix; /**< Adjacency matrix representing the roads between cities. */
    int K1; /**< First candidate city for the headquarters. */
    int K2; /**< Second candidate city for the headquarters. */
    int L; /**< Maximum number of intermediate cities. */

    /**
     * @brief Performs BFS to find cities reachable from a given city within a given limit of intermediate cities.
     * @param start The starting city.
     * @return A vector of integers representing the reachable cities.
     */
    std::vector<int> BFS(int start);
};

#endif // CORPORATIONHQ_H
