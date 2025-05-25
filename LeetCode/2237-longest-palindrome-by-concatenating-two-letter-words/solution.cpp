class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        std::unordered_map<std::string, int> counts;
        for(std::string s : words) {
            counts[s]++;
        }

        int count = 0;

        for(std::string s : words) {
            if(counts[s] == 0) {
                continue;
            }

            std::string reversed_s = rev(s);

            int num_of_pairs;
            if(s == reversed_s) {
                num_of_pairs = counts[s] / 2;
            }
            else {
                num_of_pairs = std::min(counts[s], counts[reversed_s]);
            }

            counts[s] -= num_of_pairs;
            counts[reversed_s] -= num_of_pairs;
            count += num_of_pairs;
        }

        count *= 4;

        for(std::pair<std::string, int> p : counts) {
            if(p.second > 0 && isTheSameReversed(p.first)) {
                count += 2;
                break;
            }
        }

        return count;
    }

private:

    inline std::string rev(std::string s) {
        if(isTheSameReversed(s)) {
            return s;
        }

        std::string r(1, s[1]);
        r += s[0];
        return r;
    }

    inline bool isTheSameReversed(std::string s) {
        return s[1] == s[0];
    }
};
