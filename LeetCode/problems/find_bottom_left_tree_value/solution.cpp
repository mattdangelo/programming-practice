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
    int findBottomLeftValue(TreeNode* root) {
        // Perform a BFS and go layer by layer
        std::vector<TreeNode*> current;
        current.push_back(root);

        while(!current.empty()) {
            std::vector<TreeNode*> next_current;
            for(TreeNode* t : current) {
                // Push it's neighbours onto next_current
                if(t->left) {
                    next_current.push_back(t->left);
                }

                if(t->right) {
                    next_current.push_back(t->right);
                }
            }

            // current points to the last layer, since next_current is empty
            if(next_current.empty()) {
                return current[0]->val;
            }

            current = next_current;
        }

        return -1;
    }
};