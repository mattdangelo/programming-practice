/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int total = 0;

    std::vector<int> stack;

    int getStackCount() {
        int local_total = 0;
        unsigned int multi = 1;
        for(int i=stack.size() - 1;i>=0;i--) {
            local_total += multi * stack[i];
            multi *= 10;
        }

        return local_total;
    }
 
    void recSumNumbers(TreeNode* root) {
        stack.push_back(root->val);

        if(root->left) {
            recSumNumbers(root->left);
        }

        if(root->right) {
            recSumNumbers(root->right);
        }

        if(!root->left && !root->right) {
            total += getStackCount();
        }

        stack.pop_back();
    }
public:
    int sumNumbers(TreeNode* root) {
        // The depth of the tree will not exceed 10
        stack.reserve(10);

        recSumNumbers(root);

        return total;
    }
};
