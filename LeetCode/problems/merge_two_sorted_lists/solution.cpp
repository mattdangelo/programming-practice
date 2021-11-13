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
        if(l1 == nullptr) {
            return l2;
        }
        else if(l2 == nullptr) {
            return l1;
        }

        // At this point, l1 and l2 are populated
        ListNode* new_list = new ListNode(INT_MAX);
        ListNode* tail = new_list;
        
        auto l1_ptr = l1;
        auto l2_ptr = l2;
        
        while(l1_ptr != nullptr || l2_ptr != nullptr) {
            int val_to_use;
            if(l1_ptr == nullptr) {
                val_to_use = l2_ptr->val;
                l2_ptr = l2_ptr->next;
            }
            else if(l2_ptr == nullptr) {
                val_to_use = l1_ptr->val;
                l1_ptr = l1_ptr->next;
            }
            else {
                if(l1_ptr->val < l2_ptr->val) {
                    val_to_use = l1_ptr->val;
                    l1_ptr = l1_ptr->next;
                }
                else {
                    val_to_use = l2_ptr->val;
                    l2_ptr = l2_ptr->next;
                }
            }
            tail->next = new ListNode(val_to_use);
            tail = tail->next;
        }

        return new_list->next;
    }
};