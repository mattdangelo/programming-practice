/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode start = null;
        ListNode end = null;

        while(l1 != null || l2 != null) {
            if(l1 == null || ((l2 != null) && l2.val < l1.val)) {
                ListNode temp = new ListNode(l2.val);
                if(end == null) {
                    start = temp;
                    end = start;
                }
                else {
                    end.next = temp;
                    end = temp;
                }
                l2 = l2.next;
            }
            else {
                ListNode temp = new ListNode(l1.val);
                if(end == null) {
                    start = temp;
                    end = start;
                }
                else {
                    end.next = temp;
                    end = temp;
                }
                l1 = l1.next;
            }
        }

        return start;
    }
}
