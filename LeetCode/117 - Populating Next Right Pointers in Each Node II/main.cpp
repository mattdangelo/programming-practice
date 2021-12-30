#include <iostream>
#include <deque>

#include "../shared/utils.h"
#include "../shared/node.h"

Node* connect(Node* root) {
    std::deque<Node*> BFSq;
    if (root != nullptr) {
        BFSq.push_back(root);
    }

    while (!BFSq.empty()) {
        int to_pop = BFSq.size();
        /* Update pointers here */
        for (int i = 0; i < to_pop; i++) {
            if ((i + 1) >= to_pop) {
                BFSq[i]->next = nullptr;
            }
            else {
                BFSq[i]->next = BFSq[i + 1];
            }
        }

        for (int i = 0; i < to_pop; i++) {
            Node* front = BFSq.front();
            if (front->left != nullptr) {
                BFSq.push_back(BFSq.front()->left);
            }

            if (front->right != nullptr) {
                BFSq.push_back(BFSq.front()->right);
            }

            BFSq.pop_front();
        }
    }

    return root;
}

int main() {
    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->right = new Node(7);

    Node* res = connect(head);

    utils::print_binary_tree_next_BFS(res);
}