#include <iostream>
#include <unordered_map>

#include "../shared/treenode.h"

int DFS(TreeNode* root, bool came_from_left) {
    if(root->left == nullptr && root->right == nullptr) {
        return came_from_left ? root->val : 0;
    }

    int ret = 0;
    if(root->left != nullptr) {
        ret += DFS(root->left, true);
    }

    if(root->right != nullptr) {
        ret += DFS(root->right, false);
    }

    return ret;
}

int sumOfLeftLeaves(TreeNode* root) {
    return DFS(root, false);
}

int main() {
    auto* head = new TreeNode(3);
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->left = new TreeNode(15);
    head->right->right = new TreeNode(7);

    std::cout << sumOfLeftLeaves(head) << std::endl;

    return 0;
}