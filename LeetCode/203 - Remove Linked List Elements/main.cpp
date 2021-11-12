#include <iostream>

#include "../shared/listnode.h"

ListNode* removeElements(ListNode* head, int val) {
    if(head == nullptr) {
        return nullptr;
    }

    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = head->next;

    while(current != nullptr) {
        if(current->val == val) {
            if(prev == nullptr) {
                head = head->next;
            }
            else {
                prev->next = next;
            }
        }
        else {
            prev = current;
        }
        current = next;
        next = next == nullptr ? nullptr : next->next;
    }

    return head;
}

int main() {
//    auto* head = new ListNode(1);
//    head->next = new ListNode(2);
//    head->next->next = new ListNode(6);
//    head->next->next->next = new ListNode(3);
//    head->next->next->next->next = new ListNode(4);
//    head->next->next->next->next->next = new ListNode(5);
//    head->next->next->next->next->next->next = new ListNode(6);


    auto* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    ListNode* result = removeElements(head, 2);

    while(result != nullptr) {
        std::cout << result->val << std::endl;
        result = result->next;
    }

    return 0;
}