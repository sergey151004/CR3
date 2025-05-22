/* Задание №X: Построение дерева выражения из постфиксной нотации
   и преобразование операций деления в их эквивалентные значения */
   
#ifndef EXPRESSION_TREE_H_
#define EXPRESSION_TREE_H_

#include <stack>
#include <fstream>
#include <stdexcept>

namespace expr_tree {

/**
 * @brief Структура узла дерева выражения
 */
struct TreeNode {
    int value;           ///< Значение узла (операция или число)
    TreeNode* left;      ///< Левый потомок
    TreeNode* right;     ///< Правый потомок
    
    /**
     * @brief Конструктор узла дерева
     * @param val Значение узла
     */
    explicit TreeNode(int val = 0) : value(val), left(nullptr), right(nullptr) {}
};

/**
 * @brief Класс для работы с деревом выражения
 */
class ExpressionTree {
private:
    TreeNode* root_;     ///< Корневой узел дерева
    
    /**
     * @brief Создает новый узел дерева
     * @param val Значение узла
     * @return Указатель на созданный узел
     */
    TreeNode* createNode(int val) {
        return new TreeNode(val);
    }
    
    /**
     * @brief Освобождает память, выделенную под дерево
     * @param node Корневой узел поддерева
     */
    void destroyTree(TreeNode* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
    
    /**
     * @brief Вычисляет значение поддерева
     * @param node Корневой узел поддерева
     * @return Вычисленное значение
     */
    int calculateSubtreeValue(TreeNode* node) const {
        if (!node) return 0;
        if (node->value >= 0) return node->value;
        
        int leftVal = calculateSubtreeValue(node->left);
        int rightVal = calculateSubtreeValue(node->right);
        
        switch (node->value) {
            case -1: return leftVal + rightVal;  // Сложение
            case -2: return leftVal - rightVal;  // Вычитание
            case -3: return leftVal * rightVal;  // Умножение
            case -4: return leftVal / rightVal;  // Деление
            case -5: return leftVal % rightVal;  // Остаток
            case -6: return leftVal ^ rightVal;  // Возведение в степень
            default: throw std::invalid_argument("Неверная операция");
        }
    }
    
    /**
     * @brief Преобразует поддерево с операцией деления в значение
     * @param node Корневой узел поддерева
     * @return Указатель на новый узел с вычисленным значением
     */
    TreeNode* transformDivision(TreeNode* node) {
        if (!node) return nullptr;
        
        // Рекурсивно преобразуем поддеревья
        node->left = transformDivision(node->left);
        node->right = transformDivision(node->right);
        
        // Если текущий узел содержит операцию деления или остаток
        if (node->value == -4 || node->value == -5) {
            int result = calculateSubtreeValue(node);
            TreeNode* newNode = createNode(result);
            destroyTree(node);  // Освобождаем память старого узла
            return newNode;
        }
        
        return node;
    }

public:
    /**
     * @brief Конструктор класса ExpressionTree
     */
    ExpressionTree() : root_(nullptr) {}
    
    /**
     * @brief Деструктор класса ExpressionTree
     */
    ~ExpressionTree() {
        destroyTree(root_);
    }
    
    /**
     * @brief Построение дерева выражения из файла
     * @param filename Имя входного файла
     * @throw std::runtime_error при ошибке чтения файла
     */
    void buildFromPostfix(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Ошибка открытия файла");
        }
        
        std::stack<TreeNode*> stack;
        std::string token;
        
        while (file >> token) {
            int val = std::stoi(token);
            
            if (val >= 0) {  // Операнд
                stack.push(createNode(val));
            } else {  // Операция
                if (stack.size() < 2) {
                    throw std::invalid_argument("Неверный формат постфиксной записи");
                }
                
                TreeNode* right = stack.top();
                stack.pop();
                TreeNode* left = stack.top();
                stack.pop();
                
                TreeNode* newNode = createNode(val);
                newNode->left = left;
                newNode->right = right;
                stack.push(newNode);
            }
        }
        
        if (stack.empty()) {
            throw std::invalid_argument("Пустое выражение");
        }
        
        root_ = stack.top();
        stack.pop();
        
        if (!stack.empty()) {
            throw std::invalid_argument("Несбалансированное выражение");
        }
        
        // Преобразуем все операции деления в значения
        root_ = transformDivision(root_);
    }
    
    /**
     * @brief Получение указателя на корень дерева
     * @return Указатель на корневой узел
     */
    TreeNode* getRoot() const {
        return root_;
    }
};

}  // namespace expr_tree

#endif  // EXPRESSION_TREE_H_