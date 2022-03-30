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
    bool recIsValidBST(TreeNode* root, bool gt_set, int greater_than, bool lt_set, int less_than) {
        if(root == nullptr) {
            return true;
        }

        if(gt_set && (root->val <= greater_than)) {
            return false;
        }
    
        if(lt_set && (root->val >= less_than)) {
            return false;
        }
    
        return recIsValidBST(root->left, gt_set, greater_than, true, min(less_than, root->val)) &&
               recIsValidBST(root->right, true, max(greater_than, root->val), lt_set, less_than);
    }
    
    bool isValidBST(TreeNode* root) {
        return recIsValidBST(root->left, false, INT32_MIN, true, root->val) && recIsValidBST(root->right, true, root->val, false, INT32_MAX);
    }
};