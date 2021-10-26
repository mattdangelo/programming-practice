# Maximum Subarray

### https://leetcode.com/problems/maximum-subarray/

### Notes:

* If the local sum we have so far is < 0, bound it to 0
* Add the current value to the local count
* max = max(local, max)