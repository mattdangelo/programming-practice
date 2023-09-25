class Solution {
    int score(vector<int>& row) {
        int score = 0;
        for(int i : row) {
            if(i == 0) {
                score++;
            }
        }
        return score;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        std::map<int, std::vector<int>> score_to_index;
        for(int i=0;i<mat.size();i++) {
            auto r = mat[i];
            int s = score(r);
            if(score_to_index.count(s)) {
                score_to_index[s].push_back(i);
            }
            else {
                score_to_index[s] = {i};
            }
        }

        map<int, std::vector<int>>::reverse_iterator it;
        std::vector<int> res;
        res.reserve(k);
 
        for (it = score_to_index.rbegin(); it != score_to_index.rend(); it++) {
            for(int i=0; i<it->second.size();i++) {
                res.push_back(it->second[i]);
                if(res.size() == k) {
                    return res;
                }
            }
        }

        return {};
    }
};