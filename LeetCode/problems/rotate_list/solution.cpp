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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == nullptr) {
            return head;
        }

        int length = 1;
        ListNode* ptr = head;
        while(ptr->next != nullptr) {
            length++;
            ptr = ptr->next;
        }
        ptr->next = head;
        
        k = k % length;
        int count = 0;
        while(count < length - k) {
            ptr = ptr->next;
            count++;
        }
        
        ListNode* ret = ptr->next;
        ptr->next = nullptr;
        
        return ret;
    }
};