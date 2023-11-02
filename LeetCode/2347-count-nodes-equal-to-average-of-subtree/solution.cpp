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
    int res = 0;
    std::unordered_map<TreeNode*, std::pair<int, int>> metadata;
public:
    void recAverageOfSubtree(TreeNode* root) {
        if(root->left) {
            averageOfSubtree(root->left);
        }

        if(root->right) {
            averageOfSubtree(root->right);
        }

        int root_sum;
        int root_count;

        if(metadata.count(root->left) && metadata.count(root->right)) {
            // This node has the metadata for it's left and right subtrees, calculate the average of them
            std::pair<int, int> left_avg = metadata[root->left];
            std::pair<int, int> right_avg = metadata[root->right];
            root_sum = left_avg.first + right_avg.first + root->val;
            root_count = left_avg.second + right_avg.second + 1;
        }
        else if(metadata.count(root->left)) {
            // Left subtree only
            root_sum = metadata[root->left].first + root->val;
            root_count = metadata[root->left].second + 1;
        }
        else if(metadata.count(root->right)) {
            // Right subtree only
            root_sum = metadata[root->right].first + root->val;
            root_count = metadata[root->right].second + 1;
        }
        else {
            // Leaf node - trivially 1, since anything divided by 1 will be itself
            root_sum = root->val;
            root_count = 1;
        }

        if(root_sum / root_count == root->val) {
            res++;
        }

        metadata[root] = { root_sum, root_count };
    }

    int averageOfSubtree(TreeNode* root) {
        recAverageOfSubtree(root);
        return res;
    }
};
