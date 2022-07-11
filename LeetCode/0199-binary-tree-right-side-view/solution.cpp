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
    void recRightSideView(TreeNode* root, std::vector<int>& best, int vert) {
        if(root == nullptr) {
            return;
        }
        
        if(best.size() <= vert) {
            best.push_back(root->val);
        }

        if(root->right) {
            recRightSideView(root->right, best,vert + 1);
        }
        
        if(root->left) {
            recRightSideView(root->left, best, vert + 1);
        }
        

    }
    
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> best;
        best.reserve(100);

        recRightSideView(root, best, 0);

        return best;
    }
};
