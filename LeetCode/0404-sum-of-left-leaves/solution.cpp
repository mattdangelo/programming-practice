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
    int count;

    void recSumOfLeftLeaves(TreeNode* root, bool came_from_left) {
        if(!root->left && !root->right) {
            // Check left leaf status
            if(came_from_left) {
                count += root->val;
            }
        }
        
        if(root->left) {
            // Go left
            recSumOfLeftLeaves(root->left, true);
        }

        if(root->right) {
            // Go right
            recSumOfLeftLeaves(root->right, false);
        }
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        count = 0;
        recSumOfLeftLeaves(root, false);
        return count;
    }
};
