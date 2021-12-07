struct ListNode {
    int val;
    ListNode* next;
    ListNode() {}
    ListNode(int val) { this->val = val; this->next = nullptr; }
    ListNode(int val, ListNode* next) { this->val = val; this->next = next; }
};
