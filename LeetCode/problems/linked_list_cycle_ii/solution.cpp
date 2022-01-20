/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* hare = head;
        ListNode* tortise = head;
        ListNode* meet = nullptr;

        while(hare != nullptr) {
            tortise = tortise->next;
            hare = hare->next;
            if(hare != nullptr) {
                hare = hare->next;
            }
            else {
                break;
            }
            
            if(hare == tortise) {
                meet = hare;
                break;
            }
        }
        
        if(meet == nullptr) {
            return nullptr;
        }
        else {
            hare = head;
            while(hare != tortise) {
                tortise = tortise->next;
                hare = hare->next;
            }
            return hare;
        }
        
        return nullptr;
    }
};