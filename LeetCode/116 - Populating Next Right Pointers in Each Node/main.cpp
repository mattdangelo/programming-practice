#include <iostream>

#include "../shared/node.h"
#include "../shared/utils.h"

void DFS(Node* curr, Node* next) {
    if (curr == nullptr) {
        return;
    }
    curr->next = next;
    DFS(curr->left, curr->right);
    DFS(curr->right, curr->next == nullptr ? nullptr : curr->next->left);
}

Node* connect(Node* root) {
    DFS(root, nullptr);
    return root;
}

int main() {
    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(6);
    head->right->right = new Node(7);

    Node* res = connect(head);

    utils::print_binary_tree_next_BFS(res);
}
