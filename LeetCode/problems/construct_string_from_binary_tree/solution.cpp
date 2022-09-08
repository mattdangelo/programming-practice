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
    std::string s = "";
public:

    void recTree2str(TreeNode* root) {
        s.append(std::to_string(root->val));
        if(root->left) {
            s.append("(");
            recTree2str(root->left);
            s.append(")");
        }
        else if(root->right) {
            s.append("()");
        }
        
        if(root->right) {
            s.append("(");
            recTree2str(root->right);
            s.append(")");
        }
        
        return;
    }

    string tree2str(TreeNode* root) {
        recTree2str(root);
        return s;
    }
};