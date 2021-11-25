# Length of Last Word

### https://leetcode.com/problems/length-of-last-word/

### Notes:

* Start from the end of the string and iterate until you find a non ' ' character
* Reduce index until you find a ' ', everything before this is the last word
* Calculate the length