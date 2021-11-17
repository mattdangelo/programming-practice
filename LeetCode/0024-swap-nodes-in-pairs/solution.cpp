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
    ListNode* recSwapPairs(ListNode* current, ListNode* pointed_by) {
        if(current == nullptr || current->next == nullptr) {
            return current;
        }
        
        ListNode* next = current->next;
        current->next = next->next;
        next->next = current;
        if(pointed_by != nullptr) {
            pointed_by->next = next;
        }
        
        recSwapPairs(current->next, current);
        return next;
    }
    
    ListNode* swapPairs(ListNode* head) {
        return recSwapPairs(head, nullptr);
    }
};
