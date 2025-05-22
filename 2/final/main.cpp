/**
 * Продолжение задания CR32_R: Разбор и упрощение выражений в обратной польской нотации.
 */

#include "rpn.h"
#include <iostream>
#include <locale>

int main() {
    setlocale(LC_ALL, "");

    const std::string filename = "filename.txt";
    rpn::Node* root = nullptr;

    // Построение дерева из файла
    root = rpn::buildTree(filename);
    if (!root) return 1;

    // Вывод дерева и результата до упрощения
    std::cout << "Дерево до упрощения: ";
    rpn::printTreeInfix(root, std::cout);
    std::cout << "\n";

    int preResult;
    if (rpn::eval(root, preResult)) {
        std::cout << "Результат до упрощения: " << preResult << "\n";
    }
    else {
        std::cerr << "Ошибка вычисления до упрощения\n";
    }

    // Упрощение операций '/' и '%'
    rpn::eliminateDivisions(root);

    // Вывод дерева и результата после упрощения
    std::cout << "Дерево после упрощения: ";
    rpn::printTreeInfix(root, std::cout);
    std::cout << "\n";

    int postResult;
    if (rpn::eval(root, postResult)) {
        std::cout << "Результат после упрощения: " << postResult << "\n";
    }
    else {
        std::cerr << "Ошибка вычисления после упрощения\n";
    }

    delete root;
    return 0;
}