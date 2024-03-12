class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ptr_1 = 0;
        int ptr_2 = 0;

        while(ptr_1 < nums1.size() && ptr_2 < nums2.size()) {
            if(nums1[ptr_1] < nums2[ptr_2]) {
                ptr_1++;
            }
            else if (nums1[ptr_1] > nums2[ptr_2]) {
                ptr_2++;
            }
            else {
                return nums1[ptr_1];
            }
        }

        return -1;
    }
};
