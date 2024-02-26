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
    bool recIsSameTree(TreeNode* p, TreeNode* q) {
        if(p->val != q->val) {
            return false;
        } 

        bool left_path_same;
        if(p->left && q->left) {
            left_path_same = recIsSameTree(p->left, q->left);
        }
        else if(p->left == nullptr && q->left == nullptr) {
            left_path_same = true;
        }
        else {
            return false;
        }

        bool right_path_same;
        if(p->right && q->right) {
            right_path_same = recIsSameTree(p->right, q->right);
        }
        else if(p->right == nullptr && q->right == nullptr) {
            right_path_same = true;
        }
        else {
            return false;
        }

        return left_path_same && right_path_same;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) {
            return true;
        }
        else if(p == nullptr || q == nullptr) {
            return false;
        }

        return recIsSameTree(p, q);
    }
};
