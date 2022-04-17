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
    TreeNode* start = nullptr;
    TreeNode* head = nullptr;
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root->left) {
            increasingBST(root->left);
        }
        
        if(head == nullptr) {
            head = new TreeNode(root->val);
            start = head;
        }
        else {
            head->right = new TreeNode(root->val);
            head = head->right;
        }

        if(root->right) {
            increasingBST(root->right);
        }
        
        return start;
    }
};
