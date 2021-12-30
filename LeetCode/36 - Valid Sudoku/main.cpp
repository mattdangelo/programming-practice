#include <iostream>
#include <vector>
#include <unordered_set>

bool isValidSudoku(std::vector<std::vector<char>>& board) {
    std::vector<std::unordered_set<char>> rows(9);
    std::vector<std::unordered_set<char>> cols(9);
    std::vector<std::unordered_set<char>> boxes(9);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];
            if (c != '.') {
                int box_idx = (i / 3) + 3 * (j / 3);
                if (rows[i].count(c) != 0 || cols[j].count(c) != 0 || boxes[box_idx].count(c)) {
                    return false;
                }
                else {
                    rows[i].insert(c);
                    cols[j].insert(c);
                    boxes[box_idx].insert(c);
                }
            }
        }
    }

    return true;
}

int main() {
    std::vector<std::vector<char>> input = {
        { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };

    std::cout << isValidSudoku(input) << std::endl;
}