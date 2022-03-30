class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        int l1_ptr = 0;
        int l2_ptr = 0;

        std::vector<int> result;

        while (l1_ptr != nums1.size() && l2_ptr != nums2.size()) {
            if (nums1[l1_ptr] == nums2[l2_ptr]) {
                result.push_back(nums1[l1_ptr]);
                l1_ptr++;
                l2_ptr++;
            }
            else if (nums1[l1_ptr] < nums2[l2_ptr]) {
                l1_ptr++;
            }
            else {
                l2_ptr++;
            }
        }

        return result;
    }
};