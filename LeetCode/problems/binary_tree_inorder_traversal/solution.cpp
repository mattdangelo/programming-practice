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
public:
    void recIn(TreeNode* root, std::vector<int>& current) {
        if(!root) {
            return;
        }

        recIn(root->left, current);
        current.push_back(root->val);
        recIn(root->right, current);
        return;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> cur;
        recIn(root, cur);
        return cur;
    }
};