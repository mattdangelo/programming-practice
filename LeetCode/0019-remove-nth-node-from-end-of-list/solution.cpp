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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) {
            return nullptr;
        }
        
        ListNode* left = head;
        ListNode* right = head;
        
        int count = 0;
        while(right != nullptr) {
            right = right->next;
            if(count > n) {
                left = left->next;
            }
            count++;
        }
        
        if(left->next == nullptr || count == n) {
            head = head->next;
        }
        else {
            left->next = left->next->next;
        }
        
        return head;
    }
};
