class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        
        int res = 0;
        for(int i=0;i<nums1.size();i++) {
            res += (nums1[i] * nums2[nums2.size() - 1 - i]);
        }
        
        return res;
    }
};