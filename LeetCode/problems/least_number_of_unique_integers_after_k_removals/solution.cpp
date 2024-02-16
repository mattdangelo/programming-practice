class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        std::vector<std::pair<int, int>> count_vec;
        std::unordered_map<int, int> count_map;

        for(int i : arr) {
            count_map[i]++;
        }
        
        count_vec.reserve(count_map.size());
        for(std::pair<int, int> p : count_map) {
            count_vec.push_back(p);
        }

        std::sort(count_vec.begin(), count_vec.end(), [](const auto &left, const auto &right) {
            return left.second < right.second;
        });

        int total = count_vec.size();
        for(int i=0;i<count_vec.size();i++) {
            int count_of_element = count_vec[i].second;
            if(k >= count_of_element) {
                total -= 1;
                k -= count_of_element;
            }
            else {
                // We can't subtract anymore
                break;
            }
        }

        return total;
    }
};