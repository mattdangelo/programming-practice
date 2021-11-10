#include <iostream>
#include <unordered_set>

#include "../shared/listnode.h"

bool hasCycle(ListNode *head) {
    std::unordered_set<ListNode*> visited;

    while(head != nullptr) {
        if(visited.count(head)) {
            return true;
        }
        else {
            visited.insert(head);
        }
        head = head->next;
    }

    return false;
}

int main() {
    auto head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    std::cout << hasCycle(head) << std::endl;

    return 0;
}