class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // 1. Construct a list with each score and its corresponding index
        std::vector<std::vector<int>> rankings(score.size());
        for(int i=0;i<score.size();i++) {
            rankings[i] = { score[i], i };
        }

        // 2. Sort the list by the score
        std::sort(rankings.begin(), rankings.end(), [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
            return lhs[0] > rhs[0];
        });

        // 3. Construct a mapping from the index to the order
        int index_to_rank[score.size()];
        for(int i=0;i<rankings.size();i++) {
            index_to_rank[rankings[i][1]] = i;
        }

        // 4. Construct final vector and substitute in text
        std::vector<std::string> res(score.size());
        for(int i=0;i<score.size();i++) {
            int placement = index_to_rank[i] + 1;
            if(placement == 1) {
                res[i] = "Gold Medal";
            }
            else if(placement == 2) {
                res[i] = "Silver Medal";
            }
            else if(placement == 3) {
                res[i] = "Bronze Medal";
            }
            else {
                res[i] = std::to_string(placement);
            }
        }

        return res;
    }
};
