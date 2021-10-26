#include <iostream>
#include <vector>
#include "../shared/listnode.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* l1_ptr = l1;
    ListNode* l2_ptr = l2;
    ListNode* start = nullptr;
    ListNode* end = nullptr;

    bool carry = false;
    while(l1_ptr != nullptr || l2_ptr != nullptr) {
        int sum = (l1_ptr == nullptr ? 0 : l1_ptr->val) + (l2_ptr == nullptr ? 0 : l2_ptr->val) ;

        if(carry) {
            sum++;
            carry = false;
        }

        // Check if we need to carry
        if (sum > 9) {
            sum = sum - 10;
            carry = true;
        }

        // Init the list, otherwise add a new node to it
        if(start == nullptr) {
            start = new ListNode(sum);
            end = start;
        }
        else {
            auto* temp = new ListNode(sum);
            end->next = temp;
            end = temp;
        }

        // If the pointers are already null, just leave them. We will
        // coerce them to 0 at the start of the next loop
        if(l1_ptr != nullptr) {
            l1_ptr = l1_ptr->next;
        }

        if(l2_ptr != nullptr) {
            l2_ptr = l2_ptr->next;
        }
    }

    // Check for any lingering carries
    if(carry) {
        end->next = new ListNode(1);
    }

    return start;
}

int main() {
    auto* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    auto* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* res = addTwoNumbers(l1, l2);

    while(res != nullptr) {
        std::cout << res->val << std::endl;
        res = res->next;
    }
}
