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
    int pseudo_palindromic_count;
    bool even_count[10];
public:
    void recPseudoPalindromicPaths (TreeNode* root) {
        if(root->left) {
            // Take the left path, and undo the change after we return
            even_count[root->left->val - 1] = !even_count[root->left->val - 1];
            recPseudoPalindromicPaths(root->left);
            even_count[root->left->val - 1] = !even_count[root->left->val - 1];
        }
 
        if(root->right) {
            // Take the right path, and undo the change after we return
            even_count[root->right->val - 1] = !even_count[root->right->val - 1]; 
            recPseudoPalindromicPaths(root->right);
            even_count[root->right->val - 1] = !even_count[root->right->val - 1];
        }
 
        if(!root->left && !root->right) {
            // If every number is even, or there is only 1 odd, then the path is 
            // considered "palindromic"
            int odd_count = 0;
            for(int i=0;i<10;i++) {
                if(!even_count[i]) {
                    odd_count++;
                    if(odd_count > 1) {
                        goto early_exit;
                    }
                }
            }
            pseudo_palindromic_count++;
            early_exit:
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        // Initialize counts
        pseudo_palindromic_count = 0;
        for(int i=0;i<10;i++) {
            even_count[i] = true;
        }

        // The root element will always start with an odd count
        even_count[root->val - 1] = false;

        recPseudoPalindromicPaths(root);
        return pseudo_palindromic_count;
    }
};
