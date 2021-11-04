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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p == nullptr) != (q == nullptr)) {
            return false;
        }

       if(p == nullptr && q == nullptr) {
            return true;
        }
        
        if(p->val != q->val) {
            return false;
        }

        if(p->left == nullptr && p->right == nullptr) {
            if(q->left == nullptr && q->right == nullptr) {
                return true;
            }
            else {
                return false;
            }
        }

        bool left_true;
        if(p->left != nullptr) {
            if(q->left != nullptr) {
                left_true = isSameTree(p->left, q->left);
            }
            else {
                left_true = false;
            }
        }
        else {
            if(q->left != nullptr) {
                left_true = false;
            }
            else {
                left_true = true;
            }
        }

        bool right_true;
        if(p->right != nullptr) {
            if(q->right != nullptr) {
                right_true = isSameTree(p->right, q->right);
            }
            else {
                right_true = false;
            }
        }
        else {
            if(q->right != nullptr) {
                right_true = false;
            }
            else {
                right_true = true;
            }
        }

        return left_true && right_true;
    }
};
