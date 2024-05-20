class Solution {
    std::vector<int> ret;
    bool presence[100][3] = {0};

    // Count the number of unique sets a particular value is in
    int count_unique_sets(int value) {
        return presence[value][0] + presence[value][1] + presence[value][2];
    }

    // Mark an element as present in the set, and add to the result set if appropriate
    void presence_in_set(int value, int set) {
        bool present_before = presence[value][set];
        presence[value][set] = true;
        int count_after = count_unique_sets(value);

        // If we crossed the threshold, add it to the result set
        if(!present_before && count_after == 2) {
            // Add 1 to the return values to undo the map in step 1
            ret.push_back(value + 1);
        }
    }
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        // ret could only ever be as large as the smallest vector
        ret.reserve(std::min(nums1.size(), std::min(nums2.size(), nums3.size())));

        // Subtract 1 from each of the elements to map them to the range 0 - 99
        for(int i : nums1) {
            presence_in_set(i - 1, 0);
        }

        for(int i : nums2) {
            presence_in_set(i - 1, 1);
        }

        for(int i : nums3) {
            presence_in_set(i - 1, 2);
        }

        return ret;
    }
};
