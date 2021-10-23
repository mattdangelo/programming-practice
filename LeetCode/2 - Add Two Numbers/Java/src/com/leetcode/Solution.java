package com.leetcode;

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode l1_ptr = l1;
        ListNode l2_ptr = l2;
        ListNode start = null;
        ListNode end = null;

        boolean carry = false;
        while(l1_ptr != null || l2_ptr != null) {
            int sum = (l1_ptr == null ? 0 : l1_ptr.val) + (l2_ptr == null ? 0 : l2_ptr.val) ;

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
            if(start == null) {
                start = new ListNode(sum);
                end = start;
            }
            else {
                ListNode temp = new ListNode(sum);
                end.next = temp;
                end = temp;
            }

            // If the pointers are already null, just leave them. We will
            // coerce them to 0 at the start of the next loop
            if(l1_ptr != null) {
                l1_ptr = l1_ptr.next;
            }

            if(l2_ptr != null) {
                l2_ptr = l2_ptr.next;
            }
        }

        // Check for any lingering carries
        if(carry) {
            end.next = new ListNode(1);
        }

        return start;
    }
}
