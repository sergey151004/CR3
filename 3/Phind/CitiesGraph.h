/* 
 * CityReachability.h
 * 
 * Класс для определения достижимых городов из двух штаб-квартир с ограничением на количество промежуточных городов.
 */

#ifndef CITYREACHABILITY_H_
#define CITYREACHABILITY_H_

#include <vector>
#include <queue>

class CityReachability {
public:
    /**
     * @brief Конструктор класса для работы с графом городов
     * 
     * @param n Количество городов в графе
     */
    explicit CityReachability(int n);

    /**
     * @brief Инициализирует матрицу смежности из файла
     * 
     * @param filename Имя файла с матрицей смежности
     * @return true если файл успешно прочитан
     * @return false если возникла ошибка при чтении файла
     */
    bool initializeFromMatrixFile(const std::string& filename);

    /**
     * @brief Находит города, достижимые из обеих штаб-квартир с ограничением на количество промежуточных городов
     * 
     * @param k1 Номер первой штаб-квартиры (1-based index)
     * @param k2 Номер второй штаб-квартиры (1-based index)
     * @param l Максимальное количество промежуточных городов
     * @return Вектор номеров достижимых городов или пустой вектор если таких нет
     */
    std::vector<int> findCommonlyReachableCities(int k1, int k2, int l);

private:
    /**
     * @brief Проверяет корректность номера города
     * 
     * @param city Номер города для проверки
     */
    void validateCityNumber(int city);

    /**
     * @brief Находит все достижимые города из заданной начальной точки
     * 
     * @param start Начальный город
     * @param max_intermediate Максимальное количество промежуточных городов
     * @return Вектор номеров достижимых городов
     */
    std::vector<int> findReachableCities(int start, int max_intermediate);

    std::vector<std::vector<bool>> adjacency_matrix_;  // Матрица смежности графов
};