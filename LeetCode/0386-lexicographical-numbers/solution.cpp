class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        res.reserve(n);

        int current = 1;

        while(res.size() < n) {
            res.push_back(current);

            if(current * 10 <= n) {
                // If we can multiply by and still be less than the max, do it
                current *= 10;
            }
            else {
                // If current is at the max value, or the last digit is a 9,
                // we want to / 10, and add 1
                while(current == n || current % 10 == 9) {
                    current = current / 10;
                }
                current++;
            }
        }

        return res;
    }
};
