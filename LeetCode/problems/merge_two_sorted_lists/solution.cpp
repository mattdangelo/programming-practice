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
    struct compare {
        bool operator() (ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        }
    };
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        priority_queue<ListNode*, std::vector<ListNode*>, compare> prq;
        
        if(l1 == nullptr) {
            return l2;
        }
        else if(l2 == nullptr) {
            return l1;
        }
        
        prq.push(l1);
        prq.push(l2);
        
        ListNode* temp = new ListNode(-1);
        ListNode* ptr = temp;
        
        while(!prq.empty()) {
            ListNode* popped = prq.top();
            prq.pop();
            
            if(popped->next != nullptr) {
                prq.push(popped->next);
            }

            ptr->next = popped;
            ptr = ptr->next;
        }
        
        return temp->next;
    }
};