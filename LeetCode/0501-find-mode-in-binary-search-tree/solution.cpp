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
    int val = INT_MIN;
    int frequency = 0;
    int max_frequency = 0;
    std::vector<int> res;
public:
    void recFindMode(TreeNode* root) {
        if(!root) {
            return;
        }

        recFindMode(root->left);
        if(val == root->val) {
            frequency++;
        }
        else {
            val = root->val;
            frequency = 1;
        }

        if(frequency > max_frequency) {
            max_frequency = frequency;
            res = {root->val};
        }
        else if(frequency == max_frequency) {
            res.push_back(root->val);
        }

        recFindMode(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        recFindMode(root);
        return res;
    }
};
