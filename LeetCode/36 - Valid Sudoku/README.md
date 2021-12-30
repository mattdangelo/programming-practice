# Valid Sudoku

### https://leetcode.com/problems/valid-sudoku/

### Notes:

* Keep track of 3 vectors of sets: row, col and box
* Iterate over the elements and check if char in the corresponding set has repeats
* Can calculate the box index with (i / 3) + 3 * (j / 3);