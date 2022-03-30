/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    struct comp {
        auto operator() (const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
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
};