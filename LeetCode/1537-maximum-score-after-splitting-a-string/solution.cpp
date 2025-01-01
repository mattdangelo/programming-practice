class Solution {
public:
    int maxScore(string s) {
        // Start with everything but the first element in the right partition
        int left = s[0] == '0';
        int right = 0;
        for(int i=1;i<s.length();i++) {
            if(s[i] == '1') {
                right++;
            }
        }

        // Keep track of the max score
        int max_score = left + right;

        // Selectively move elements from the right to the left, checking if we
        // exceeded the previous max
        for(int i=1;i<s.length() - 1;i++) {
            if(s[i] == '0') {
                left++;
            }

            if(s[i] == '1') {
                right--;
            }

            max_score = std::max(max_score, left + right);
        }

        return max_score;
    }
};
