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
    int length;
    ListNode* ptr;
    ListNode* head;
    Solution(ListNode* head) {
        ptr = head;
        head = head;
        length = 0;
        while(ptr != nullptr) {
            ptr = ptr->next;
            length++;
        }
        ptr = head;
    }
    
    int getRandom() {
        ListNode* ptr2 = ptr;
        int jump = rand() % length;
        for(int i=0;i<jump;i++) {
            ptr2 = ptr2->next;
            if(ptr2 == nullptr) {
                ptr2 = head;
            }
        }
        return ptr2->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */