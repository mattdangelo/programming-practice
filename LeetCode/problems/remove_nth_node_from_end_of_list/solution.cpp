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
        ListNode* before_nth = nullptr;

        int i = 0;
        ListNode* ptr = head;
        while(ptr != nullptr) {
            ptr = ptr->next;
            i++;
            if(i > n) {
                if(before_nth == nullptr) {
                    before_nth = head;
                }
                else {
                    before_nth = before_nth->next;
                }
            }
        }
        
        if(before_nth == nullptr) {
            head = head->next;
        }
        else {
            before_nth->next = before_nth->next->next;
        }
        
        return head;
    }
};