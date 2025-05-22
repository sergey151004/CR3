#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include "ExpressionTree.h"

int main() {
    std::string filename;
    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл." << std::endl;
        return 1;
    }

    std::string expression;
    file >> expression;
    file.close();

    ExpressionTree tree;
    Node* root = tree.buildTree(expression);
    if (!root) {
        std::cerr << "Ошибка: неверное выражение." << std::endl;
        return 1;
    }

    root = tree.transformTree(root);
    std::cout << "Указатель на корень полученного дерева: " << root << std::endl;

    return 0;
}
