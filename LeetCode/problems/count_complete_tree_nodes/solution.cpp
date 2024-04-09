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
    int countNodes(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }

    int l_count = 1;
    TreeNode* l_deep = root->left;
    while(l_deep != nullptr) {
        l_deep = l_deep->left;
        l_count++;
    }

    int r_count = 1;
    TreeNode* r_deep = root->right;
    while(r_deep != nullptr) {
        r_deep = r_deep->right;
        r_count++;
    }

    if(l_count == r_count) {
        return (std::pow(2, l_count)  - 1);
    }
    else {
        // This tree has the discrepancy
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
    }
};