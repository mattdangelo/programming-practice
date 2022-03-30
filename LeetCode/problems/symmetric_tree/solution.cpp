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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> bfs;
        bfs.push(root);
        
        while(!bfs.empty()) {
            // Get all the neighbours of the nodes on the queue and check them
            std::vector<TreeNode*> popped;
            while(!bfs.empty()) {
                if(bfs.front()->left != nullptr) {
                    popped.push_back(bfs.front()->left);
                }
                else {
                    // Treat IN32_MAX nodes as "null"
                    popped.push_back(new TreeNode(INT32_MAX));
                }
                
                if(bfs.front()->right != nullptr) {
                    popped.push_back(bfs.front()->right);
                }
                else {
                    // Treat IN32_MAX nodes as "null"
                    popped.push_back(new TreeNode(INT32_MAX));
                }
                
                bfs.pop();
            }
            
            int left = 0;
            int right = popped.size() - 1;
            
            while(left < right) {
                if(popped[left]->val != popped[right]->val) {
                    return false;
                }
                left++;
                right--;
            }
            
            for(TreeNode* t : popped) {
                // Don't add null nodes back into the tree
                if(t->val != INT32_MAX) {
                    bfs.push(t);
                }
            }
        }
        
        return true;
    }
};