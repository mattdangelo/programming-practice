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
public:
    int recFindTilt(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        
        int left_total = recFindTilt(root->left);
        int right_total = recFindTilt(root->right);
        
        count += abs(left_total - right_total);
        return left_total + right_total + root->val;
    }
    
    int findTilt(TreeNode* root) {
        recFindTilt(root);
        return count;
    }
};