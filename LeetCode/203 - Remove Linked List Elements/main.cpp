#include <iostream>

#include "../shared/utils.h"
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
    auto* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    ListNode* res = removeElements(head, 2);

    utils::print_linked_list(res);

    return 0;
}