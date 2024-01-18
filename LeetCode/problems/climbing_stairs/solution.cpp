class Solution {
    // Cache
    int cache[46] = {};
public:
    Solution() {
        // Base cases (0, 1 and 2 steps)
        for(int i=0;i<3;i++) {
            cache[i] = i;
        }
    }

    int climbStairs(int n) { 
        int ctr = 3;
        while(ctr <= n) {
            cache[ctr] = cache[ctr - 1] + cache[ctr - 2];
            ctr++;
        }

        return cache[n];
    }
};