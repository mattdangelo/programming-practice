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
    vector<vector<int>> results;

    void recPathSum(TreeNode* root, int targetSum, int currentSum, vector<int>& currentValues) {
        currentValues.push_back(root->val);
        currentSum += root->val;
        if(root->left == nullptr && root->right == nullptr) {
            if(currentSum == targetSum) {
                results.push_back(currentValues);
                currentValues.pop_back();
                currentSum -= root->val;
                return;
            }
        }

        if(root->left) {
            recPathSum(root->left, targetSum, currentSum, currentValues);
        }

        if(root->right) {
            recPathSum(root->right, targetSum, currentSum, currentValues);
        }

        currentValues.pop_back();
        currentSum -= root->val;
        return;
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> currentValues;
        currentValues.reserve(5000);

        if(root != nullptr) {
            recPathSum(root, targetSum, 0, currentValues);
        }

        return results;
    }
};
