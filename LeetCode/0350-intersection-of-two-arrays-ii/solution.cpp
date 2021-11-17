class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> res;
        
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        int n1_ptr = 0;
        int n2_ptr = 0;
        
        while(n1_ptr < nums1.size() && n2_ptr < nums2.size()) {
            if(nums1[n1_ptr] < nums2[n2_ptr]) {
                n1_ptr++;
            }
            else if(nums1[n1_ptr] > nums2[n2_ptr]) {
                n2_ptr++;
            }
            else {
                res.push_back(nums1[n1_ptr]);
                n1_ptr++;
                n2_ptr++;
            }   
        }
        
        return res;
    }
};
