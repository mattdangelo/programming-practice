# Zigzag Conversion

### https://leetcode.com/problems/zigzag-conversion/

### Notes:

* Iterate over all chars, keep a seperate ptr between 0 and numRows - 1
* Have a boolean mode flag that says whether we're rising or falling
* Insert the characters into an array of strings based on the ptr value
* Update ptr value based on whether we're in rising or falling mode