# Insert into a Binary Search Tree

### https://leetcode.com/problems/insert-into-a-binary-search-tree/

### Notes:

* Walk the BST going left and right until you hit a nullptr
* Keep track of the previous node also
* Insert the node to the left or right of prev when you hit nullptr
* Watch out for case where the whole tree is empty