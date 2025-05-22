#include "rpn.h"
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdexcept>

namespace rpn {

    Node::Node(int v) : val(v), left(nullptr), right(nullptr) {}

    Node::~Node() {
        delete left;
        delete right;
    }

    void cleanupStack(std::stack<Node*>& s) {
        while (!s.empty()) {
            delete s.top();
            s.pop();
        }
    }

    Node* buildTree(const std::string& filename) {
        std::ifstream in(filename);
        if (!in) {
            std::cerr << "Ошибка: не удалось открыть файл " << filename << '\n';
            return nullptr;
        }

        std::stack<Node*> st;
        std::string token;

        while (in >> token) {
            if (token.size() == 1 && std::isdigit(token[0])) {
                int operand = token[0] - '0';
                st.push(new Node(operand));
            }
            else if (token.size() == 1) {
                char op = token[0];
                int code = -100;

                switch (op) {
                case '+': code = -1; break;
                case '-': code = -2; break;
                case '*': code = -3; break;
                case '/': code = -4; break;
                case '%': code = -5; break;
                case '^': code = -6; break;
                default:
                    std::cerr << "Ошибка: неизвестная операция " << op << '\n';
                    cleanupStack(st);
                    return nullptr;
                }

                if (st.size() < 2) {
                    std::cerr << "Ошибка: недостаточно операндов для '" << op << "'\n";
                    cleanupStack(st);
                    return nullptr;
                }

                Node* right = st.top(); st.pop();
                Node* left = st.top(); st.pop();
                Node* node = new Node(code);
                node->left = left;
                node->right = right;
                st.push(node);
            }
            else {
                std::cerr << "Ошибка: некорректный токен " << token << '\n';
                cleanupStack(st);
                return nullptr;
            }
        }

        if (st.size() != 1) {
            std::cerr << "Ошибка: в стеке " << st.size() << " элементов вместо 1\n";
            cleanupStack(st);
            return nullptr;
        }

        return st.top();
    }

    bool eval(Node* node, int& result) {
        if (!node) {
            std::cerr << "Ошибка: null узел\n";
            return false;
        }

        if (node->val >= 0) {
            result = node->val;
            return true;
        }

        int L, R;
        if (!eval(node->left, L)) return false;
        if (!eval(node->right, R)) return false;

        switch (node->val) {
        case -1: result = L + R; return true;
        case -2: result = L - R; return true;
        case -3: result = L * R; return true;
        case -4:
            if (R == 0) {
                std::cerr << "Деление на ноль\n";
                return false;
            }
            result = L / R;
            return true;
        case -5:
            if (R == 0) {
                std::cerr << "Остаток от деления на ноль\n";
                return false;
            }
            result = L % R;
            return true;
        case -6:
            if (L == 0 && R == 0) {
                std::cerr << "0^0 не определено\n";
                return false;
            }
            result = static_cast<int>(std::pow(L, R));
            return true;
        default:
            std::cerr << "Неизвестная операция в узле\n";
            return false;
        }
    }

    void eliminateDivisions(Node*& node) {
        if (!node) return;

        eliminateDivisions(node->left);
        eliminateDivisions(node->right);

        if (node->val == -4 || node->val == -5) {
            int value;
            if (eval(node, value)) {
                delete node->left;
                delete node->right;
                node->left = nullptr;
                node->right = nullptr;
                node->val = value;
            }
            else {
                std::cerr << "Ошибка упрощения узла\n";
            }
        }
    }

    void printTreeInfix(Node* node, std::ostream& out) {
        if (!node) return;

        if (node->val >= 0) {
            out << node->val;
        }
        else {
            out << '(';
            printTreeInfix(node->left, out);

            char op;
            switch (node->val) {
            case -1: op = '+'; break;
            case -2: op = '-'; break;
            case -3: op = '*'; break;
            case -4: op = '/'; break;
            case -5: op = '%'; break;
            case -6: op = '^'; break;
            default: op = '?';
            }

            out << ' ' << op << ' ';
            printTreeInfix(node->right, out);
            out << ')';
        }
    }

} // namespace rpn