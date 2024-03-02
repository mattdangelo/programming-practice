class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        uint size = nums.size();
        std::vector<int> res(size);
        int n_left = 0;
        int n_right = size - 1;
        uint res_ptr = size - 1;

        while(n_left <= n_right) {
            int left = nums[n_left];
            int right = nums[n_right];
            if(abs(left) > abs(right)) {
                res[res_ptr] = pow(left, 2);
                n_left++;
            }
            else {
                res[res_ptr] = pow(right, 2);
                n_right--;
            }
            res_ptr--;
        }

        return res;
    }
};
