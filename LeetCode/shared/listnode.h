struct ListNode {
    int val;
    ListNode* next;
    ListNode() {}
    ListNode(int val) { this->val = val; this->next = nullptr; }
    ListNode(int _val, ListNode* _next) : val(_val), next(_next) { }
};
