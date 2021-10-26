# Invert Binary Tree

### https://leetcode.com/problems/invert-binary-tree/

### Notes:

* Iterate down the tree swapping left and right. If one is null, swap it to the other. 
* Check for initial nullptr and return nullptr
* If left and right are null, just return root