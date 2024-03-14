class Solution {
    std::vector<std::vector<std::string>> solutions;
    int board_size;

    void recSolveNQueens(std::vector<string>& working_board, std::set<int>& pos_diagonals, std::set<int>& neg_diagonals, std::set<int>& cols, int row) {
        if(board_size == row) {
            // Add to solution set
            solutions.push_back(working_board);
            return;
        }

        for(int i=0;i<working_board.size();i++) {
            if(cols.contains(i) || pos_diagonals.contains(row + i) || neg_diagonals.contains(row - i)) {
                continue;
            }

            working_board[row][i] = 'Q';
            pos_diagonals.insert(row + i);
            neg_diagonals.insert(row - i);
            cols.insert(i);

            recSolveNQueens(working_board, pos_diagonals, neg_diagonals, cols, row + 1);

            working_board[row][i] = '.';
            pos_diagonals.erase(row + i);
            neg_diagonals.erase(row - i);
            cols.erase(i);
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        board_size = n;
        std::vector<string> working_board(n);
        for(int i=0;i<board_size;i++) {
            std::string row = "";
            for(int i=0;i<board_size;i++) {
                row += ".";
            }
            working_board[i] = row;
        }

        std::set<int> pos_diagonals;
        std::set<int> neg_diagonals;
        std::set<int> cols;

        recSolveNQueens(working_board, pos_diagonals, neg_diagonals, cols, 0);

        return solutions;
    }
};
