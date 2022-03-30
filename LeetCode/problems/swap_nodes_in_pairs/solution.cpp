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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        else if (head->next == nullptr) {
            return head;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = curr->next;
        ListNode* ret = next;

        while (curr != nullptr && next != nullptr) {
            // Swap
            curr->next = next->next;
            next->next = curr;

            if (prev) {
                prev->next = next;
            }

            // Update
            prev = curr;
            curr = curr->next;
            if (curr == nullptr) {
                break;
            }
            next = curr->next;
        }

        return ret;
    }
};