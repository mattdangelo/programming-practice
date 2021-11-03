#include <iostream>

#include "../shared/treenode.h"

int current = 0;

void DFS(TreeNode* root, int level) {
    current = current > level ? current : level;
    if(root->left != nullptr) {
        DFS(root->left, level + 1);
    }

    if(root->right != nullptr) {
        DFS(root->right, level + 1);
    }
}

int maxDepth(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }

    DFS(root, 1);
    return current;
}

int main() {
    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->left = new TreeNode(15);
    head->right->right = new TreeNode(7);

    std::cout << maxDepth(head) << std::endl;

    return 0;
}