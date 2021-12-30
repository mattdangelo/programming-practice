#include <iostream>
#include <string>
#include <queue>

#include "../utils.h"
#include "../node.h"
#include "../treenode.h"
#include "../listnode.h"

template <typename T>
void utils::print_binary_tree_vals_BFS(T* head)
{
    std::queue<T*> BFS;
    BFS.push(head);

    while (!BFS.empty()) {
        T* top = BFS.front();
        std::cout << top->val << " ";

        if (top->left != nullptr) {
            BFS.push(top->left);
        }

        if (top->right != nullptr) {
            BFS.push(top->right);
        }

        BFS.pop();
    }
}

template void utils::print_binary_tree_vals_BFS<TreeNode>(TreeNode* head);

template <typename T>
void utils::print_binary_tree_next_BFS(T* head)
{
    std::queue<T*> BFS;
    BFS.push(head);

    while(!BFS.empty()) {
        T* top = BFS.front();
        std::cout << top->val << " "
                  << (top->next == nullptr ? "#" : std::to_string(top->next->val))  << "\n";

        if (top->left != nullptr) {
            BFS.push(top->left);
        }

        if (top->right != nullptr) {
            BFS.push(top->right);
        }

        BFS.pop();
    }
}

template void utils::print_binary_tree_next_BFS<Node>(Node* head);

template <typename T>
void utils::print_linked_list(T* head)
{
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
}

template void utils::print_linked_list<ListNode>(ListNode* head);