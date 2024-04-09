class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Special case - only 1 person
        if(trust.size() == 0 && n == 1) {
            return 1;
        }
    
        std::vector<int> trust_factor(n, 0);

        // Pass 1: Calculate the sum of relationships for each person, and filter out people
        // who trust others
        for(std::vector<int> relationship : trust) {
            // Use 0 offsetting
            trust_factor[relationship[1] - 1]++;
            trust_factor[relationship[0] - 1]--;
        }

        // Pass 2: Find person who matches the properties
        for(int i=0;i<n;i++) {
            if(trust_factor[i] == n - 1) {
                // Convert to 1 indexed result
                return i + 1;
            } 
        }

        return -1;
    }
};