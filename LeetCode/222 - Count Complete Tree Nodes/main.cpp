#include <iostream>
#include <cmath>
#include "../shared/treenode.h"

int countNodes(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }

    int l_count = 1;
    TreeNode* l_deep = root->left;
    while(l_deep != nullptr) {
        l_deep = l_deep->left;
        l_count++;
    }

    int r_count = 1;
    TreeNode* r_deep = root->right;
    while(r_deep != nullptr) {
        r_deep = r_deep->right;
        r_count++;
    }

    if(l_count == r_count) {
        return (std::pow(2, l_count)  - 1);
    }
    else {
        // This tree has the discrepancy
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
}

int main() {
    auto* head = new TreeNode(1);

    head->left = new TreeNode(2);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);

    head->right = new TreeNode(3);
    head->right->left = new TreeNode(6);

    std::cout << countNodes(head) << std::endl;

    return 0;
}
