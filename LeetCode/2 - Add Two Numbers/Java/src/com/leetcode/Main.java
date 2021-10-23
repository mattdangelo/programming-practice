package com.leetcode;

public class Main {

    public static void main(String[] args) {
	    Solution s = new Solution();

        ListNode l1 = new ListNode(2);
        l1.next = new ListNode(4);
        l1.next.next = new ListNode(3);

        ListNode l2 = new ListNode(5);
        l2.next = new ListNode(6);
        l2.next.next = new ListNode(4);

        ListNode res = s.addTwoNumbers(l1, l2);

        while(res != null) {
            System.out.println(res.val);
            res = res.next;
        }
    }
}
