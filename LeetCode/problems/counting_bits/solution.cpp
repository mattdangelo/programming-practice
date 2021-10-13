class Solution {
public:
    vector<int> countBits(int n) {
        auto result = std::vector<int>();
        result.reserve(n + 1);
        result.push_back(0);
        for (int i = 1; i < n+1; i++) {
            int query = i;
            int count = 0;
            while (query) {
                if (query & 1) {
                    count++;
                }
                query = query >> 1;
            }
            result.push_back(count);
        }
        return result;
    }
};