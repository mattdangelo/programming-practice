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
    std::vector<int> res;
public:
    vector<int> largestValues(TreeNode* root) {
        std::vector<TreeNode*> neighbours;
        if(root) {
            neighbours.push_back(root);
        }

        while(!neighbours.empty()) {
            std::vector<TreeNode*> new_neighbours;

            int level_max = INT_MIN;

            for(TreeNode* t : neighbours) {
                if(t->left) {
                    new_neighbours.push_back(t->left);
                }

                if(t->right) {
                    new_neighbours.push_back(t->right);
                }

                level_max = std::max(t->val, level_max);
            }

            res.push_back(level_max);
            neighbours = new_neighbours;
        }

        return res;
    }
};
