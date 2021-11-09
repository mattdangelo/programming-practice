class Solution {
    std::unordered_map<int, int> memo;
public:
    int numTrees(int n) {
        if(n <= 1) {
            return 1;
        }

        int res = 0;
        for(int i=0;i<n;i++) {
            int partial_sum;

            if(memo.count(i) == 0) {
                memo[i] = numTrees(i);
            }
            partial_sum = memo[i];

            if(memo.count(n - i - 1) == 0) {
                memo[n - i - 1] = numTrees(n - i - 1);
            }
            partial_sum *= memo[n - i - 1];

            res += partial_sum;
        }

        return res;
    }
};
