class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::unordered_set<char>> rows(9);
        std::vector<std::unordered_set<char>> cols(9);
        std::vector<std::unordered_set<char>> boxes(9);
        
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                char c = board[i][j];
                if(c != '.') {
                    int box_idx = (i / 3) + 3 * (j / 3);
                    if(rows[i].count(c) != 0 || cols[j].count(c) != 0 || boxes[box_idx].count(c)) {
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
};
