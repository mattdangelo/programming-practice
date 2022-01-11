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
    int count = 0;
    std::vector<bool> stack;
public:
    void DFS(TreeNode* root) {
        if(root == nullptr) {
            return; 
        }
        
        stack.push_back(root->val);
        
        if(root->left == nullptr && root->right == nullptr) {
            string val;
            for(bool b : stack) {
                val += b ? "1" : "0";
            }
            count += stoi(val, nullptr, 2);
        }
        
        DFS(root->left);
        DFS(root->right);
        stack.pop_back();
    }

    int sumRootToLeaf(TreeNode* root) {
        DFS(root);
        return count;
    }
};
