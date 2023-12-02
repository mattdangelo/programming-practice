#define ASCII_CHAR_OFFSET 97
#define ALPHABET_SIZE 26

class Solution {
public:
    int canFormFromChars(const std::string& word, const int(&global_char_count)[ALPHABET_SIZE]) {
        int local_char_count[ALPHABET_SIZE];
        memset(local_char_count, 0, sizeof(local_char_count));

        for(char c : word) {
            int idx = c - ASCII_CHAR_OFFSET;
            local_char_count[idx]++;
            if(local_char_count[idx] > global_char_count[idx]) {
                return 0;
            }
        }

        return word.size();
    }

    int countCharacters(vector<string>& words, string chars) {
        int char_count[ALPHABET_SIZE];
        memset(char_count, 0, sizeof(char_count));

        for(char c : chars) {
            char_count[c - ASCII_CHAR_OFFSET]++;
        }

        int count = 0;
        for(std::string w : words) {
            count += canFormFromChars(w, char_count);
        }

        return count;
    }
};
