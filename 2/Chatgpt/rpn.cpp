/* Продолжение задания: Обратная польская запись. Дерево выражения. */

#include "ExpressionTree.h"
#include <stack>
#include <sstream>
#include <iostream>
#include <memory>
#include <stdexcept>

namespace {
    /**
     * @brief Проверяет, является ли токен операцией.
     */
    bool isOperator(const std::string& token) {
        return token == "+" || token == "-" || token == "*" ||
               token == "/" || token == "%" || token == "^";
    }

    /**
     * @brief Преобразует строку операции в числовой код.
     */
    int getOpCode(const std::string& op) {
        if (op == "+") return -1;
        if (op == "-") return -2;
        if (op == "*") return -3;
        if (op == "/") return -4;
        if (op == "%") return -5;
        if (op == "^") return -6;
        throw std::runtime_error("Unknown operator: " + op);
    }

    /**
     * @brief Вычисляет значение операции.
     */
    int evaluate(int a, int b, int opCode) {
        switch (opCode) {
            case -1: return a + b;
            case -2: return a - b;
            case -3: return a * b;
            case -4:
                if (b == 0) throw std::runtime_error("Division by zero");
                return a / b;
            case -5:
                if (b == 0) throw std::runtime_error("Modulo by zero");
                return a % b;
            case -6: {
                int result = 1;
                for (int i = 0; i < b; ++i)
                    result *= a;
                return result;
            }
            default:
                throw std::runtime_error("Unknown operation code: " + std::to_string(opCode));
        }
    }

    /**
     * @brief Освобождает левое и правое поддеревья и заменяет узел на константу.
     */
    void replaceWithConstant(Node*& node, int value) {
        delete node->left;
        delete node->right;
        node->value = value;
        node->left = nullptr;
        node->right = nullptr;
    }

    /**
     * @brief Рекурсивно вычисляет значение поддерева.
     */
    int computeSubtreeValue(Node* node) {
        if (!node->left && !node->right) {
            return node->value;
        }

        int leftVal = computeSubtreeValue(node->left);
        int rightVal = computeSubtreeValue(node->right);

        return evaluate(leftVal, rightVal, node->value);
    }
}

Node* buildExpressionTree(const std::string& rpn) {
    std::istringstream iss(rpn);
    std::stack<Node*> nodes;
    std::string token;

    while (iss >> token) {
        if (token.size() != 1) {
            throw std::runtime_error("Invalid token: " + token);
        }

        char ch = token[0];

        if (std::isdigit(ch)) {
            nodes.push(new Node(ch - '0'));
        } else if