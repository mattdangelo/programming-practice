class Solution {
    #define ASCII_OFFSET 97
public:
    int longestPalindrome(vector<string>& words) {
        int pal_length = 0;

        for(std::string s : words) {
            set_count(s[0], s[1], get_count(s[0], s[1]) + 1);

            // If the count of rev_s is 0, there's no point trying to
            // extend the palindrome
            if(get_count(s[1], s[0]) == 0) {
                continue;
            }

            int num_of_pairs;
            if(is_the_same_reversed(s)) {
                num_of_pairs = get_count(s[0], s[1]) / 2;
            }
            else {
                num_of_pairs = std::min(get_count(s[0], s[1]), get_count(s[1], s[0]));
            }

            set_count(s[0], s[1], get_count(s[0], s[1]) - num_of_pairs);
            set_count(s[1], s[0], get_count(s[1], s[0]) - num_of_pairs);
            pal_length += num_of_pairs;
        }

        pal_length *= 4;

        for(std::string s : words) {
            if(is_the_same_reversed(s) && get_count(s[0], s[1]) > 0) {
                pal_length += 2;
                break;
            }
        }

        return pal_length;
    }

private:
    int counts[26][26] = { 0 };

    bool is_the_same_reversed(std::string& s) {
        return s[1] == s[0];
    }

    int get_count(char first, char second) {
        return counts[first - ASCII_OFFSET][second - ASCII_OFFSET];
    }

    void set_count(char first, char second, int count) {
        counts[first - ASCII_OFFSET][second - ASCII_OFFSET] = count;
    }
};
