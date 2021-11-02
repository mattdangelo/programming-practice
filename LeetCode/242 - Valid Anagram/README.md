# Valid Anagram

### https://leetcode.com/problems/valid-anagram/

### Notes:

* Map counts of each char from 1 string
* Subtract the counts in the map of the chars from the other string
* Check all values in the map are 0

* Alternatively, sort both strings
* go through each of them and check that s[i] == t[i]