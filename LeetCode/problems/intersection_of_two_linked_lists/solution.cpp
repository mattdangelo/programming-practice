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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int size_a = 0;
        ListNode* temp = headA;
        while(temp != nullptr) {
            temp = temp->next;
            size_a++;
        }
        
        int size_b = 0;
        temp = headB;
        while(temp != nullptr) {
            temp = temp->next;
            size_b++;
        }
        
        ListNode* longer;
        ListNode* shorter;
        int diff;
        if(size_a > size_b) {
            longer = headA;
            shorter = headB;
            diff = size_a - size_b;
        }
        else {
            longer = headB;
            shorter = headA;
            diff = size_b - size_a;
        }
        
        for(int i=0;i<diff;i++) {
            longer = longer->next;
        }
        
        while(shorter != longer) {
            shorter = shorter->next;
            longer = longer->next;
        }
        
        if(shorter != nullptr) {
            return shorter;
        }
        
        return nullptr;
    }
};