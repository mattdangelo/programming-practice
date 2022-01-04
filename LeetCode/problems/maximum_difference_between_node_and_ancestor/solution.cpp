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
    int max_diff = INT32_MIN;
public:
    std::vector<int> maxAnDFS(TreeNode* root) {
        std::vector<int> left; 
        if(root->left == nullptr) {
            left = { root->val, root->val };
        }
        else {
            left = maxAnDFS(root->left);
        }
        
        std::vector<int> right;
        if(root->right == nullptr) {
            right = { root->val, root->val };
        }
        else {
            right = maxAnDFS(root->right);
        }
        
        int min = std::min(left[0], right[0]);
        int max = std::max(left[1], right[1]);

        if(abs(min - root->val) > max_diff || abs(max - root->val) > max_diff) {
            max_diff = std::max(abs(min - root->val), abs(max - root->val));
        }
        
        return {std::min(min, root->val), std::max(max, root->val)};
    }
    
    int maxAncestorDiff(TreeNode* root) {
        maxAnDFS(root);
        return max_diff;
    }
};