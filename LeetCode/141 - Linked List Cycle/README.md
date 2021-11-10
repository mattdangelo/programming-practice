# Linked List Cycle

### https://leetcode.com/problems/linked-list-cycle/

### Notes:

* Keep a hashset of visited nodes
* To do it with O(1) memory, have a runner and walker pointer
* Runner strides 2 nodes at a time, walker does 1 at a time
* if they meet, cycle
* If both get to the end of the list, no cycle