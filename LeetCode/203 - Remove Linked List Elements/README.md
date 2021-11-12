# Remove Linked List Elements

### https://leetcode.com/problems/remove-linked-list-elements/

### Notes:

* Keep track of current, prev and next pointers
* set prev->next to next if value of current matches
* Be careful if prev is initially nullptr, need to move head to head->next instead of setting prev->next