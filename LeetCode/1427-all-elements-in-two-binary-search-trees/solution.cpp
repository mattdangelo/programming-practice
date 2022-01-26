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
    void DFSPop(TreeNode* root, std::vector<int>& to_pop) {
        if(root == nullptr) {
            return;
        }
        
        to_pop.push_back(root->val);
        
        if(root->left) {
            DFSPop(root->left, to_pop);
        }
        
        if(root->right) {
            DFSPop(root->right, to_pop);
        }
    }
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        std::vector<int> values;
        DFSPop(root1, values);
        DFSPop(root2, values);
        
        std::sort(values.begin(), values.end());
        return values;
    }
};
