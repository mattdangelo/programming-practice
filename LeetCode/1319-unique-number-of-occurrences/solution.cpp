class Solution {
    std::unordered_map<int, int> counts;
public:
    bool uniqueOccurrences(vector<int>& arr) {
        for(int i : arr) {
            if(counts.count(i)) {
                counts[i]++;
            }
            else {
                counts[i] = 1;
            }
        }

        std::unordered_set<int> count_counts;
        for(std::pair<int, int> count : counts) {
            if(count_counts.count(count.second)) {
                return false;
            }
            else {
                count_counts.insert(count.second);
            }
        }

        return true;
    }
};
