/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    std::unordered_map<Node*, Node*> mapping;
public:
    Node* copyRandomList(Node* head) {
        // 2 Passes, first pass create new linked list, second pass, populate random values
        Node* new_ll_head = nullptr;

        Node* new_ll_ptr = new_ll_head;
        Node* old_ll_ptr = head;

        // First Pass
        while(old_ll_ptr != nullptr) {
            Node* new_node = new Node(old_ll_ptr->val);
            new_node->next = nullptr;
            new_node->random = nullptr;
            mapping[old_ll_ptr] = new_node;
            if(new_ll_ptr == nullptr) {
                new_ll_head = new_node;
                new_ll_ptr = new_node;
            }
            else {
                new_ll_ptr->next = new_node;
                new_ll_ptr = new_ll_ptr->next;
            }
            old_ll_ptr = old_ll_ptr->next;
        }

        // Second pass
        old_ll_ptr = head;
        new_ll_ptr = new_ll_head;
        while(old_ll_ptr != nullptr) {
            if(old_ll_ptr->random != nullptr) {
                mapping[old_ll_ptr]->random = mapping[old_ll_ptr->random];
            }
            old_ll_ptr = old_ll_ptr->next;
        }

        return new_ll_head;
    }
};
