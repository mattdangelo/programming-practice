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
    void reorderList(ListNode* head) {
        std::deque<ListNode*> dequeue;
        ListNode* ptr = head;
        while(ptr != nullptr) {
            dequeue.push_back(ptr);
            ptr = ptr->next;
        }
        
        ptr = head;
        dequeue.pop_front();
        bool left = false;
        while(!dequeue.empty()) {
            if(left) {
                left = !left;
                ptr->next = dequeue.front();
                ptr = ptr->next;
                dequeue.pop_front();
            }
            else {
                left = !left;
                ptr->next = dequeue.back();
                ptr = ptr->next;
                dequeue.pop_back();
            }
        }
        
        ptr->next = nullptr;
    }
};
