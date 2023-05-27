class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, bool> set;
        for(int i : nums1) {
            set.insert({i, false});
        }

        std::unordered_set<int> not_in_nums1_set;
        not_in_nums1_set.reserve(nums2.size());

        for(int i : nums2) {
            if(set.count(i)) {
                // We've "seen" the element in nums1 from nums2
                set[i] = true;
            }
            else {
                not_in_nums1_set.insert(i);
            }
        }

        std::vector<int> not_in_nums_1;
        not_in_nums_1.reserve(not_in_nums1_set.size());
        std::copy(not_in_nums1_set.begin (), not_in_nums1_set.end (), std::back_inserter(not_in_nums_1));

        std::vector<int> not_in_nums_2;
        not_in_nums_1.reserve(set.size());

        for(auto const& x : set) {
            if(!x.second) {
                not_in_nums_2.push_back(x.first);
            }
        }

        std::vector<std::vector<int>> ret = { not_in_nums_2, not_in_nums_1 };
        return ret;
    }
};
