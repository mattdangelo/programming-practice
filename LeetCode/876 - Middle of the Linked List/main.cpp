#include <iostream>

#include "../shared/listnode.h"

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast == nullptr) {
            break;
        }
        else {
            fast = fast->next;
        }
        slow = slow->next;
    }

    return slow;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* res = middleNode(head);

    std::cout << res->val << std::endl;
}