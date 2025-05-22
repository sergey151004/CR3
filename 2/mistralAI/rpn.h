#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include <string>

/**
 * @struct Node
 * @brief Структура для узла дерева выражений.
 */
struct Node {
    int value;
    Node* left;
    Node* right;
};

/**
 * @class ExpressionTree
 * @brief Класс для построения и преобразования дерева выражений.
 */
class ExpressionTree {
public:
    /**
     * @brief Строит дерево выражений из строки в обратной польской записи.
     * @param expression Строка в обратной польской записи.
     * @return Указатель на корень дерева.
     */
    Node* buildTree(const std::string& expression);

    /**
     * @brief Преобразует дерево, удаляя операции деления.
     * @param root Указатель на корень дерева.
     * @return Указатель на корень преобразованного дерева.
     */
    Node* transformTree(Node* root);

private:
    /**
     * @brief Проверяет, является ли символ оператором.
     * @param c Символ для проверки.
     * @return true, если символ является оператором, иначе false.
     */
    bool isOperator(char c);

    /**
     * @brief Применяет оператор к двум операндам.
     * @param a Первый операнд.
     * @param b Второй операнд.
     * @param op Оператор.
     * @return Результат применения оператора.
     */
    int applyOperator(int a, int b, char op);
};

#endif // EXPRESSIONTREE_H
