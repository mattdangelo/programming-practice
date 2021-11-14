# Merge k Sorted Lists

### https://leetcode.com/problems/merge-k-sorted-lists/

### Notes:

* Use a priority queue with a custom comparator for ListNodes
* Add all lists to the prio queue
* Pluck out and pop the min to iteratively build the list