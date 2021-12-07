# House Robber

### https://leetcode.com/problems/house-robber/

### Notes:

* Go recursively with index
* Return the max of nums[i] + rob(i + 2) and rob(i + 1)
* Use memoization to reduce runtime