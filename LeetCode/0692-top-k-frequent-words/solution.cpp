class Solution {
private:
    static bool compare(const std::pair<std::string, int>& lhs, const std::pair<std::string, int>& rhs) {
         if(lhs.second == rhs.second) {
            return lhs.first < rhs.first;
         }
         else {
            return lhs.second > rhs.second;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::unordered_map<std::string, int> counts;
        for(auto& s : words) {
            if(counts.count(s) == 0) {
                counts[s] = 1;
            }
            else {
                counts[s]++;
            }
        }
        
        std::vector<std::pair<std::string, int>> counts_vec;
        counts_vec.reserve(counts.size());
        for(auto& p : counts) {
            counts_vec.push_back(p);
        }

        std::priority_queue<std::pair<std::string, int>, 
                            std::vector<std::pair<std::string, int>>,
                            std::function<bool(const std::pair<std::string, int>& lhs, const std::pair<std::string, int>& rhs)>> prq(compare);
        
        for(auto& p : counts_vec) {
            prq.push(p);
            if(prq.size() > k) {
                prq.pop();
            }
        }
        
        std::vector<std::string> result(k);
        for(int i=0;i<k;i++) {
            result[k - i - 1] = prq.top().first;
            prq.pop();
        }
        
        return result;
    }
};
