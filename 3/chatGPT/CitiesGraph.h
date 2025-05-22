/* Продолжение задания №Разделение сфер влияния */

#ifndef GRAPHPROCESSOR_H
#define GRAPHPROCESSOR_H

#include <vector>
#include <string>

/**
 * @brief Класс для обработки графа и определения пересекающихся городов,
 * доступных из двух штаб-квартир не более чем через L шагов.
 */
class GraphProcessor {
public:
    /**
     * @brief Загружает матрицу смежности из файла.
     * @param filename Имя файла, содержащего данные графа.
     * @return true если загрузка успешна, иначе false.
     */
    bool loadGraphFromFile(const std::string& filename);

    /**
     * @brief Находит города, достижимые из заданного города за <= L шагов.
     * @param startCity Начальный город (1-based).
     * @param maxSteps Максимальное количество промежуточных шагов.
     * @return Вектор номеров достижимых городов.
     */
    std::vector<int> getReachableCities(int startCity, int maxSteps) const;

    /**
     * @brief Получает список городов, достижимых из обоих штаб-квартир.
     * @param k1 Первая штаб-квартира (1-based).
     * @param k2 Вторая штаб-квартира (1-based).
     * @param l Максимальное количество промежуточных шагов.
     * @return Отсортированный вектор пересекающихся городов.
     */
    std::vector<int> findCommonCities(int k1, int k2, int l) const;

private:
    int numCities_;
    std::vector<std::vector<int>> adjacencyMatrix_;

    /**
     * @brief Проверяет корректность координаты в графе.
     * @param city Номер города (1-based).
     * @return true если координата корректна.
     */
    bool isValidCity(int city) const;
};

#endif // GRAPHPROCESSOR_H