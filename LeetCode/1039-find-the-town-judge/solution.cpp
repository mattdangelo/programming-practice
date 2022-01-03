class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> counts(n, 0);
        
        for(std::vector<int> v : trust) {
            counts[v[0] - 1]--;
            counts[v[1] - 1]++;
        }

        for(int i=0;i<n;i++) {
            if(counts[i] == n - 1) {
                return i + 1;
            }
        }

        return -1;
    }
};
