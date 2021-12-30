#include <iostream>
#include <queue>

#include "../shared/utils.h"
#include "../shared/treenode.h"

TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr) {
        return nullptr;
    }

    if(root->left == nullptr && root->right == nullptr) {
        return root;
    }
    else if(root->left == nullptr) {
        root->left = root->right;
        root->right = nullptr;
        invertTree(root->left);
    }
    else if(root->right == nullptr) {
        root->right = root->left;
        root->left = nullptr;
        invertTree(root->right);
    }
    else {
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;

        invertTree(root->left);
        invertTree(root->right);
    }

    return root;
}

int main() {
    auto* r = new TreeNode(4);
    r->left = new TreeNode(2);
    r->left->left = new TreeNode(1);
    r->left->right = new TreeNode(3);

    r->right = new TreeNode(7);
    r->right->right = new TreeNode(9);
    r->right->left = new TreeNode(6);

    TreeNode* res = invertTree(r);

    utils::print_binary_tree_vals_BFS(res);

    return 0;
}