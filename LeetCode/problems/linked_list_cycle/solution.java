/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        HashSet<ListNode> visited = new HashSet<>();
        ListNode ptr = head;
        while(ptr != null) {
            if(visited.contains(ptr)) {
                return true;
            }
            else {
                visited.add(ptr);
                ptr = ptr.next;
            }
        }

        return false;
    }
}