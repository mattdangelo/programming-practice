#include <iostream>

#include "../shared/utils.h"
#include "../shared/listnode.h"

ListNode* reverseList(ListNode* head) {
    if(head == nullptr) {
        return nullptr;
    }

    ListNode* current = head;
    ListNode* prev = nullptr;

    while(current != nullptr) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int main() {
    auto* head = new ListNode(1);
    head->next = new ListNode(2);

    ListNode* res = reverseList(head);

    utils::print_linked_list(res);

    return 0;
}