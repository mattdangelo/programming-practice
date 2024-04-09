class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::set<int> s1;

        for(int i : nums1) {
            s1.insert(i);
        }

        std::vector<int> res;
        res.reserve(std::min(nums1.size(), nums2.size()));

        for(int i : nums2) {
            if(s1.contains(i)) {
                res.push_back(i);
                s1.erase(i);
            }
        }

        return res;
    }
};
