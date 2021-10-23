package com.leetcode;

public class Main {

    public static void main(String[] args) {
	    Solution s = new Solution();

        ListNode s1 = new ListNode(1);
        s1.next = new ListNode(2);
        s1.next.next = new ListNode(4);

        ListNode s2 = new ListNode(1);
        s2.next = new ListNode(3);
        s2.next.next = new ListNode(4);

        ListNode res = s.mergeTwoLists(s1, s2);

        while(res != null) {
            System.out.println(res.val);
            res = res.next;
        }
    }
}
