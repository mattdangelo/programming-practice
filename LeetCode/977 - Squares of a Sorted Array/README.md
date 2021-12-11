# Squares of a Sorted Array

### https://leetcode.com/problems/squares-of-a-sorted-array/

### Notes:

* Iterate over the list of numbers, find the split point between positive and negatives if it exists
* If not, either calculate the square of the numbers (list will be sorted either increasing or decreasing value)
* If it does, 2 pointers, remember abs()