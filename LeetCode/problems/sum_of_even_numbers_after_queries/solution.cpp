class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum_even = 0;
        std::vector<int> res(queries.size());
        for(int i : nums) {
            if(i % 2 == 0) {
                sum_even += i;
            }
        }

        for(int i=0;i<queries.size();i++) {
            int addition_value = queries[i][0];
            int index = queries[i][1];
            int old = nums[index];
            int modified = nums[index] + addition_value;

            if(old % 2 == 0) {
                // old was even
                sum_even -= old;
                if(modified % 2 == 0) {
                    // new is even
                    sum_even += modified;
                }
            }
            else {
                // old was odd
                if(modified % 2 == 0) {
                    // If the new value is even, add it to the even sum
                    sum_even += modified;
                }
            }
            
            res[i] = sum_even;
            nums[index] = modified;
        }
        
        return res;
    }
};