#include <iostream>

#include "../shared/listnode.h"

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* start = nullptr;
    ListNode* end = nullptr;

    while(l1 != nullptr || l2 != nullptr) {
        if(l1 == nullptr || ((l2 != nullptr) && l2->val < l1->val)) {
            auto* temp = new ListNode(l2->val);
            if(end == nullptr) {
                start = temp;
                end = start;
            }
            else {
                end->next = temp;
                end = temp;
            }
            l2 = l2->next;
        }
        else {
            auto* temp = new ListNode(l1->val);
            if(end == nullptr) {
                start = temp;
                end = start;
            }
            else {
                end->next = temp;
                end = temp;
            }
            l1 = l1->next;
        }
    }

    return start;
}

int main() {
    auto* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    auto* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* res = mergeTwoLists(l1, l2);

    while(res != nullptr) {
        std::cout << res->val << std::endl;
        res = res->next;
    }

    return 0;
}