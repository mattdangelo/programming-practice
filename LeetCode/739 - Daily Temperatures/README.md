# Daily Temperatures

### https://leetcode.com/problems/daily-temperatures/

### Notes:

* Create a stack
* Iterate over the temperatures start to end
* for a given element, while the stack is empty and current temp > temp of stack.top()
* pop itm save ret[idx] = current index - idx of top of stack