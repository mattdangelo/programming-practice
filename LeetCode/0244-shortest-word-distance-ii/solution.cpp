class WordDistance {
    std::unordered_map<string, vector<int>> memo;
public:
    
    WordDistance(vector<string>& wordsDict) {
        for(int i=0;i<wordsDict.size();i++) {
            if(memo.find(wordsDict[i]) != memo.end()) {
                memo[wordsDict[i]].push_back(i);
            }
            else {
               memo[wordsDict[i]] = {i}; 
            }
        }
    }
    
    int shortest(string word1, string word2) {
        std::vector<int> word_one_indexes = memo[word1];
        std::vector<int> word_two_indexes = memo[word2];
        
        int best = INT32_MAX;
        for(int i=0;i<word_one_indexes.size();i++) {
            for(int j=0;j<word_two_indexes.size();j++) {
                if(abs(word_one_indexes[i] - word_two_indexes[j]) < best) {
                    best = abs(word_one_indexes[i] - word_two_indexes[j]);
                }
            }
        }
        return best;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
