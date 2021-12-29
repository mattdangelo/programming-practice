/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        std::deque<Node*> BFSq;
        if(root != nullptr) {
            BFSq.push_back(root);
        }

        while(!BFSq.empty()) {
            int to_pop = BFSq.size();
            /* Update pointers here */
            for (int i=0;i<to_pop;i++) {
                if((i + 1) >= to_pop) {
                    BFSq[i]->next = nullptr;
                }
                else {
                    BFSq[i]->next = BFSq[i + 1];
                }
            }
            
            for(int i=0;i<to_pop;i++) {
                Node* front = BFSq.front();
                if(front->left != nullptr) {
                    BFSq.push_back(BFSq.front()->left);
                }
                
                if(front->right != nullptr) {
                    BFSq.push_back(BFSq.front()->right);
                }

                BFSq.pop_front();
            }
        }
        
        return root; 
    }
};
