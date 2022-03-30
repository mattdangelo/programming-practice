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
    
    void rangeSumBSTRec(TreeNode* root, int low, int high) {
        if(root == nullptr) {
            return;
        }
        
        if(root->val <= high && root->val >= low) {
            count += root->val;
        }
        
        rangeSumBSTRec(root->left, low, high);
        rangeSumBSTRec(root->right, low, high);
    }
    
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        rangeSumBSTRec(root, low, high);
        return count;
    }
};