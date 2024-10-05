class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Edge case - if s2 is smaller than s1, then it can't possibly contain a permutation
        if(s2.length() < s1.length()) {
            return false;
        }

        // Break up the character counts in s1
        std::unordered_map<char, int> s1_count;
        for(char c : s1) {
            s1_count[c]++;
        }

        // Sliding window approach - we know the length of the window in s2 will be of length s1
        int left = 0;
        int right = s1.length();
        std::unordered_map<char, int> s2_count;
        for(int i=0;i<right;i++) {
            s2_count[s2[i]]++;
        }

        while(right <= s2.length()) {
            if(s1_count == s2_count) {
                return true;
            }

            s2_count[s2[left]]--;
            if(s2_count[s2[left]] == 0) {
                s2_count.erase(s2[left]);
            }
            if(right < s2.length()) {
                s2_count[s2[right]]++;
            }
            left++;
            right++;
        }

        return false;
    }
};
