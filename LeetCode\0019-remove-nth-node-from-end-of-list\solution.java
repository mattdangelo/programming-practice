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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ArrayList<ListNode> elements = new ArrayList<>();
        ListNode ptr = head;
        while(ptr != null) {
            elements.add(ptr);
            ptr = ptr.next;
        }

        if(elements.size() == 1) {
            return null;
        }

        if(n == 1) {
            elements.get(elements.size() - 2).next = null;
        }
        else if((elements.size() - n - 1) < 0) {
            head = head.next;
        }
        else {
            elements.get(elements.size() - n - 1).next = elements.get(elements.size() - n + 1);
        }

        return head;
    }
}
