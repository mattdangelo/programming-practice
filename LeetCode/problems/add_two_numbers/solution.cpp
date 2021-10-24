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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1_ptr = l1;
        ListNode* l2_ptr = l2;
        ListNode* start = nullptr;
        ListNode* end = nullptr;

        bool carry = false;
        while(l1_ptr != nullptr || l2_ptr != nullptr) {
            int sum = (l1_ptr == nullptr ? 0 : l1_ptr->val) + (l2_ptr == nullptr ? 0 : l2_ptr->val) ;

            if(carry) {
                sum++;
                carry = false;
            }

            // Check if we need to carry
            if (sum > 9) {
                sum = sum - 10;
                carry = true;
            }

            // Init the list, otherwise add a new node to it
            if(start == nullptr) {
                start = new ListNode(sum);
                end = start;
            }
            else {
                auto* temp = new ListNode(sum);
                end->next = temp;
                end = temp;
            }

            // If the pointers are already null, just leave them. We will
            // coerce them to 0 at the start of the next loop
            if(l1_ptr != nullptr) {
                l1_ptr = l1_ptr->next;
            }

            if(l2_ptr != nullptr) {
                l2_ptr = l2_ptr->next;
            }
        }

        // Check for any lingering carries
        if(carry) {
            end->next = new ListNode(1);
        }

        return start;
    }
};