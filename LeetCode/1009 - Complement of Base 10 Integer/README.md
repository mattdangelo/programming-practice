# Complement of Base 10 Integer

### https://leetcode.com/problems/complement-of-base-10-integer/

### Notes:

* Build a mask while the number >> 1 is > 0
* XOR the mask with the original number
* Special case at 0 (Just return 1)