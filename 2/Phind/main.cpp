/* Задание №X: Точка входа программы */

#include "ExpressionTree.h"

namespace expr_tree {

/**
 * @brief Функция main для демонстрации работы класса ExpressionTree
 * @return Код завершения программы
 */
int main() {
    try {
        ExpressionTree tree;
        tree.buildFromPostfix("expression.txt");
        
        TreeNode* root = tree.getRoot();
        if (!root) {
            std::cerr << "Ошибка: пустое дерево выражения\n";
            return 1;
        }
        
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << '\n';
        return 1;
    }
}

}  // namespace expr_tree