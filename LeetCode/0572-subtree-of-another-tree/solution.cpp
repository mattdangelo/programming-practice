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
    bool isSameTree(TreeNode* a, TreeNode* b) {
        if((a == nullptr) && (b == nullptr)) {
            return true;
        }
        
        if((a == nullptr) != (b == nullptr)) {
            return false;
        }
        
        return a->val == b->val && isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) {
            return false;
        }
        
        if(root->val == subRoot->val) {
            // Check subtree
            bool res = isSameTree(root, subRoot);
            
            if(res) {
                return true;
            }
        }
        
        // Check left and right of root
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
