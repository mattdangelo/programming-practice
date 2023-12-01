class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        std::string word1_flattened;
        std::string word2_flattened;

        for(std::string s : word1) {
            word1_flattened += s;
        }

        for(std::string s : word2) {
            word2_flattened += s;
        }

        return word1_flattened == word2_flattened;
    }
};
