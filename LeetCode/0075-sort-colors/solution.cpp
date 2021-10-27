class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l_ptr = 0;
        int r_ptr = nums.size() - 1;
        while(l_ptr < r_ptr) {
            if(nums[l_ptr] == 0) {
                l_ptr++;
                continue;
            }

            if(nums[r_ptr] != 0) {
                r_ptr--;
                continue;
            }

            int temp = nums[l_ptr];
            nums[l_ptr] = nums[r_ptr];
            nums[r_ptr] = temp;
        }

        // l_ptr now points to the first non-0 int
        r_ptr = nums.size() - 1;
        while(l_ptr < r_ptr) {
            if(nums[l_ptr] == 1) {
                l_ptr++;
                continue;
            }

            if(nums[r_ptr] != 1) {
                r_ptr--;
                continue;
            }

            int temp = nums[l_ptr];
            nums[l_ptr] = nums[r_ptr];
            nums[r_ptr] = temp;
        }
    }
};
