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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) {
            return nullptr;
        }
        else if(head->next == nullptr) {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        
        ListNode* oddStart = odd;
        ListNode* evenStart = even;

        ListNode* ptr = even->next;

        int i = 0;
        while(ptr != nullptr) {
            if(i%2 == 0) {
                odd->next = ptr;
                odd = odd->next;
            }
            else {
                even->next = ptr;
                even = even->next;
            }
            ptr = ptr->next;
            i++;
        }
        
        even->next = nullptr;
        odd->next = evenStart;
        
        return oddStart;
    }
};