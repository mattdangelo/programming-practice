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
public:
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
};