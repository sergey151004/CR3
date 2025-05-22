/* Продолжение задания: Обратная польская запись. Дерево выражения. */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <memory>
#include <stdexcept>
#include <cctype>
#include "ExpressionTree.h"

int main() {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;

    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "Error: Cannot open file '" << filename << "'\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << fin.rdbuf();
    std::string expression = buffer.str();

    try {
        Node* root = buildExpressionTree(expression);
        std::cout << "Original tree built successfully.\n";

        simplifyTree(root);
        std::cout << "Tree simplified (no division or mod operations).\n";

        std::cout << "Resulting tree root pointer: " << root << "\n";
    } catch (const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}