#include "ExpressionTree.h"
#include <stack>
#include <cctype>

/**
 * @brief Строит дерево выражений из строки в обратной польской записи.
 * @param expression Строка в обратной польской записи.
 * @return Указатель на корень дерева.
 */
Node* ExpressionTree::buildTree(const std::string& expression) {
    std::stack<Node*> stack;

    for (char c : expression) {
        if (std::isdigit(c)) {
            Node* node = new Node{c - '0', nullptr, nullptr};
            stack.push(node);
        } else if (isOperator(c)) {
            if (stack.size() < 2) {
                std::cerr << "Ошибка: неверное выражение." << std::endl;
                return nullptr;
            }
            Node* right = stack.top();
            stack.pop();
            Node* left = stack.top();
            stack.pop();
            Node* node = new Node{applyOperator(left->value, right->value, c), left, right};
            stack.push(node);
        }
    }

    if (stack.size() != 1) {
        std::cerr << "Ошибка: неверное выражение." << std::endl;
        return nullptr;
    }

    return stack.top();
}

/**
 * @brief Преобразует дерево, удаляя операции деления.
 * @param root Указатель на корень дерева.
 * @return Указатель на корень преобразованного дерева.
 */
Node* ExpressionTree::transformTree(Node* root) {
    if (!root) {
        return nullptr;
    }

    root->left = transformTree(root->left);
    root->right = transformTree(root->right);

    if (root->value == -4 || root->value == -5) {
        int leftValue = root->left->value;
        int rightValue = root->right->value;
        int result = applyOperator(leftValue, rightValue, root->value == -4 ? '/' : '%');
        Node* newNode = new Node{result, nullptr, nullptr};
        delete root->left;
        delete root->right;
        delete root;
        return newNode;
    }

    return root;
}

/**
 * @brief Проверяет, является ли символ оператором.
 * @param c Символ для проверки.
 * @return true, если символ является оператором, иначе false.
 */
bool ExpressionTree::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

/**
 * @brief Применяет оператор к двум операндам.
 * @param a Первый операнд.
 * @param b Второй операнд.
 * @param op Оператор.
 * @return Результат применения оператора.
 */
int ExpressionTree::applyOperator(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return a % b;
        case '^': return static_cast<int>(std::pow(a, b));
        default: return 0;
    }
}
