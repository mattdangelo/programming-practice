#include <iostream>

#include "../shared/utils.h"
#include "../shared/treenode.h"

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }

    TreeNode* prev = nullptr;
    TreeNode* ptr = root;

    while (ptr != nullptr) {
        prev = ptr;
        if (ptr->val < val) {
            ptr = ptr->right;
        }
        else {
            ptr = ptr->left;
        }
    }

    if (prev->val < val) {
        prev->right = new TreeNode(val);
    }
    else {
        prev->left = new TreeNode(val);
    }

    return root;
}

int main() {
    TreeNode* head = new TreeNode(4);
    head->left = new TreeNode(2);
    head->right = new TreeNode(7);
    head->left->left = new TreeNode(1);
    head->left->right = new TreeNode(3);

    utils::print_binary_tree_vals_BFS(insertIntoBST(head, 5));
    return 0;
}