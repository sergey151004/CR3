/* ������� �X: ���������� ������ ��������� �� ����������� �������
   � �������������� �������� ������� � �� ������������� �������� */
   
#ifndef EXPRESSION_TREE_H_
#define EXPRESSION_TREE_H_

#include <stack>
#include <fstream>
#include <stdexcept>

namespace expr_tree {

/**
 * @brief ��������� ���� ������ ���������
 */
struct TreeNode {
    int value;           ///< �������� ���� (�������� ��� �����)
    TreeNode* left;      ///< ����� �������
    TreeNode* right;     ///< ������ �������
    
    /**
     * @brief ����������� ���� ������
     * @param val �������� ����
     */
    explicit TreeNode(int val = 0) : value(val), left(nullptr), right(nullptr) {}
};

/**
 * @brief ����� ��� ������ � ������� ���������
 */
class ExpressionTree {
private:
    TreeNode* root_;     ///< �������� ���� ������
    
    /**
     * @brief ������� ����� ���� ������
     * @param val �������� ����
     * @return ��������� �� ��������� ����
     */
    TreeNode* createNode(int val) {
        return new TreeNode(val);
    }
    
    /**
     * @brief ����������� ������, ���������� ��� ������
     * @param node �������� ���� ���������
     */
    void destroyTree(TreeNode* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
    
    /**
     * @brief ��������� �������� ���������
     * @param node �������� ���� ���������
     * @return ����������� ��������
     */
    int calculateSubtreeValue(TreeNode* node) const {
        if (!node) return 0;
        if (node->value >= 0) return node->value;
        
        int leftVal = calculateSubtreeValue(node->left);
        int rightVal = calculateSubtreeValue(node->right);
        
        switch (node->value) {
            case -1: return leftVal + rightVal;  // ��������
            case -2: return leftVal - rightVal;  // ���������
            case -3: return leftVal * rightVal;  // ���������
            case -4: return leftVal / rightVal;  // �������
            case -5: return leftVal % rightVal;  // �������
            case -6: return leftVal ^ rightVal;  // ���������� � �������
            default: throw std::invalid_argument("�������� ��������");
        }
    }
    
    /**
     * @brief ����������� ��������� � ��������� ������� � ��������
     * @param node �������� ���� ���������
     * @return ��������� �� ����� ���� � ����������� ���������
     */
    TreeNode* transformDivision(TreeNode* node) {
        if (!node) return nullptr;
        
        // ���������� ����������� ����������
        node->left = transformDivision(node->left);
        node->right = transformDivision(node->right);
        
        // ���� ������� ���� �������� �������� ������� ��� �������
        if (node->value == -4 || node->value == -5) {
            int result = calculateSubtreeValue(node);
            TreeNode* newNode = createNode(result);
            destroyTree(node);  // ����������� ������ ������� ����
            return newNode;
        }
        
        return node;
    }

public:
    /**
     * @brief ����������� ������ ExpressionTree
     */
    ExpressionTree() : root_(nullptr) {}
    
    /**
     * @brief ���������� ������ ExpressionTree
     */
    ~ExpressionTree() {
        destroyTree(root_);
    }
    
    /**
     * @brief ���������� ������ ��������� �� �����
     * @param filename ��� �������� �����
     * @throw std::runtime_error ��� ������ ������ �����
     */
    void buildFromPostfix(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("������ �������� �����");
        }
        
        std::stack<TreeNode*> stack;
        std::string token;
        
        while (file >> token) {
            int val = std::stoi(token);
            
            if (val >= 0) {  // �������
                stack.push(createNode(val));
            } else {  // ��������
                if (stack.size() < 2) {
                    throw std::invalid_argument("�������� ������ ����������� ������");
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
            throw std::invalid_argument("������ ���������");
        }
        
        root_ = stack.top();
        stack.pop();
        
        if (!stack.empty()) {
            throw std::invalid_argument("������������������ ���������");
        }
        
        // ����������� ��� �������� ������� � ��������
        root_ = transformDivision(root_);
    }
    
    /**
     * @brief ��������� ��������� �� ������ ������
     * @return ��������� �� �������� ����
     */
    TreeNode* getRoot() const {
        return root_;
    }
};

}  // namespace expr_tree

#endif  // EXPRESSION_TREE_H_