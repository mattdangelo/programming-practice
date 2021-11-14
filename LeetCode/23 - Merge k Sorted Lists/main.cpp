#include <iostream>
#include <vector>
#include <queue>

#include "../shared/listnode.h"

struct comp {
    auto operator() (const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    auto* head = new ListNode(INT32_MIN);
    ListNode* tail = head;

    std::priority_queue<ListNode*, std::vector<ListNode*>, comp> prq;
    for(ListNode* l : lists) {
        if(l != nullptr) {
            prq.push(l);
        }
    }

    while(!prq.empty()) {
        auto top = prq.top();
        prq.pop();
        tail->next = new ListNode(top->val);
        tail = tail->next;
        if(top->next != nullptr) {
            prq.push(top->next);
        }
    }

    return head->next;
}

int main() {
    auto* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    auto* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    auto* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    std::vector<ListNode*> input = { l1, l2, l3 };
    ListNode* result = mergeKLists(input);

    while(result != nullptr) {
        std::cout << result->val << std::endl;
        result = result->next;
    }

    return 0;
}