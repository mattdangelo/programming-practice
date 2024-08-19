class Solution {
    std::vector<std::vector<int>> cache;
    int n;
public:
    int minSteps(int n) {
        if(n == 1) {
            return 0;
        }

        this->n = n;

        cache = std::vector<std::vector<int>>(n, vector<int>(n / 2 + 1, -1));

        // Start with a copy, since we know we'll have to do something
        return recMinSteps(1, 1) + 1;
    }

private:
    int recMinSteps(int current_length, int last_paste_length) {
        if(n == current_length) {
            return 0;
        }
        else if(current_length > n) {
            return 1000;
        }

        if(cache[current_length][last_paste_length] != -1) {
            return cache[current_length][last_paste_length];
        }

        int res = std::min(recMinSteps(current_length + last_paste_length, last_paste_length) + 1, 
                           recMinSteps(current_length * 2, current_length) + 2);

        cache[current_length][last_paste_length] = res;

        return res;
    }
};
