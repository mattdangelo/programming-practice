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
    std::vector<int> root_1_leaf_nodes;
    std::vector<int> root_2_leaf_nodes;

    void recPopulate(std::vector<int>& vec, TreeNode* root) {
        if(root->left) {
            recPopulate(vec, root->left);
        }

        if(root->right) {
            recPopulate(vec, root->right);
        }

        if(!root->left && !root->right) {
            vec.push_back(root->val);
        }
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        recPopulate(root_1_leaf_nodes, root1);
        recPopulate(root_2_leaf_nodes, root2);

        if(root_1_leaf_nodes.size() != root_2_leaf_nodes.size()) {
            return false;
        }

        for(int i=0;i<root_1_leaf_nodes.size();i++) {
            if(root_1_leaf_nodes[i] != root_2_leaf_nodes[i]) {
                return false;
            }
        }

        return true;
    }
};
