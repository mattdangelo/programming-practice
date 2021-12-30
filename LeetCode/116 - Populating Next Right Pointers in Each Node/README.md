# Populating Next Right Pointers in Each Node

### https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

### Notes:

* DFS but keep track of the next node to the right in each iteration
* Set curr->next to the next right node
* DFS with left and right of current
* DFS with right and curr->next->left