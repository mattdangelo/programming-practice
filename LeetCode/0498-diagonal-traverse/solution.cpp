class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        std::vector<int> res;
        res.reserve(mat[0].size() * mat.size());

        // Special cases - matrix is 1xn or mx1
        if (mat.size() == 1) {
            return mat[0];
        }
        else if (mat[0].size() == 1) {
            for (int i = 0; i < mat.size(); i++) {
                res.push_back(mat[i][0]);
            }
            return res;
        }

        mat_x = mat.size();
        mat_y = mat[0].size();

        while (res.size() != mat.size() * mat[0].size()) {
            res.push_back(mat[cur_y][cur_x]);
            
            // Special cases - corners
            if (atTopBorder(cur_y) && atRightBorder(cur_x) && cur_direction == TOP_RIGHT) {
                cur_y = cur_y + 1;
                reverseDirection();
            }
            else if (atLeftBorder(cur_x) && atBottomBorder(cur_y) && cur_direction == BOTTOM_LEFT) {
                cur_x = cur_x + 1;
                reverseDirection();
            }
            
            // Borders
            else if (atTopBorder(cur_y) && cur_direction == TOP_RIGHT) {
                cur_x = cur_x + 1;
                reverseDirection();
            }
            else if (atLeftBorder(cur_x) && cur_direction == BOTTOM_LEFT) {
                cur_y = cur_y + 1;
                reverseDirection();
            }
            else if (atRightBorder(cur_x) && cur_direction == TOP_RIGHT) {
                cur_y = cur_y + 1;
                reverseDirection();
            }
            else if (atBottomBorder(cur_y) && cur_direction == BOTTOM_LEFT) {
                cur_x = cur_x + 1;
                reverseDirection();
            }
            else if (cur_direction == TOP_RIGHT) {
                cur_x = cur_x + 1;
                cur_y = cur_y - 1;
            }
            else {
                cur_x = cur_x - 1;
                cur_y = cur_y + 1;
            }
        }

        return res;
    }
    
private:
    enum DIRECTION { TOP_RIGHT, BOTTOM_LEFT };

    int mat_x = 0;
    int mat_y = 0;
    int cur_x = 0;
    int cur_y = 0;
    DIRECTION cur_direction = TOP_RIGHT;

    bool atLeftBorder(int x) {
        return x <= 0;
    }

    bool atRightBorder(int x) {
        return x >= mat_y - 1;
    }

    bool atTopBorder(int y) {
        return y <= 0;
    }

    bool atBottomBorder(int y) {
        return y >= mat_x - 1;
    }

    void reverseDirection() {
        if (cur_direction == TOP_RIGHT) {
            cur_direction = BOTTOM_LEFT;
        }
        else {
            cur_direction = TOP_RIGHT;
        }
    }
};

