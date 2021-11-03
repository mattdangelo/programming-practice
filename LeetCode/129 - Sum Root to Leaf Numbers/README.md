# Sum Root to Leaf Numbers

### https://leetcode.com/problems/sum-root-to-leaf-numbers/

### Notes:

* Do a DFS to iterate
* Keep a separate map of which nodes pointed a leaf node
* When you reach a node with null left and right ptrs, add the values to the total
* Check if you need to reverse the string also