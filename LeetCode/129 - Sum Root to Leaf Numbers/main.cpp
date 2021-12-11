#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>

#include "../shared/treenode.h"

int sumNumbers(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }

    int total = 0;

    std::stack<TreeNode*> dfs_stack;
    dfs_stack.push(root);
    std::unordered_map<TreeNode*, TreeNode*> call_tree;

    while(!dfs_stack.empty()) {
        TreeNode* ptr = dfs_stack.top();

        if(ptr->left == nullptr && ptr->right == nullptr) {
            std::string str_val;
            auto call_tree_ptr = ptr;
            while(call_tree_ptr != nullptr) {
                str_val += std::to_string(call_tree_ptr->val);
                call_tree_ptr = call_tree[call_tree_ptr];
            }
            std::reverse(str_val.begin(), str_val.end());
            total += stoi(str_val);
        }

        dfs_stack.pop();

        if(ptr->right != nullptr) {
            call_tree[ptr->right] = ptr;
            dfs_stack.push(ptr->right);
        }

        if(ptr->left != nullptr) {
            call_tree[ptr->left] = ptr;
            dfs_stack.push(ptr->left);
        }
    }

    return total;
}

int main() {
//    TreeNode* head = new TreeNode(1);
//    head->left = new TreeNode(2);
//    head->right = new TreeNode(3);
//

    TreeNode* head = new TreeNode(4);
    head->left = new TreeNode(9);
    head->right = new TreeNode(0);
    head->left->left = new TreeNode(5);
    head->left->right = new TreeNode(1);

    std::cout << sumNumbers(head) << std::endl;

    return 0;
}