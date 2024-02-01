class Solution {
    inline bool bufferValid(std::vector<int>& buffer, int& k) {
        if(abs(buffer[0] - buffer[2]) > k) {
            return false;
        }

        return true;
    }
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int ptr = 0;
        std::vector<std::vector<int>> result(nums.size() / 3);
        
        std::vector<int> buffer(3);
        for(int i=0;i<nums.size();i++) {
            if(i != 0 && i % 3 == 0) {
                // Check if the buffer is invalid, if so return empty array
                if(!bufferValid(buffer, k)) {
                    return {};
                }

                // Push the buffer into the result
                result[ptr] = buffer;
                ptr++;
                buffer[i % 3] = nums[i];
            }
            else {
                buffer[i % 3] = nums[i];
            }
        }

        if(!bufferValid(buffer, k)) {
            return {};
        }
  
        result[ptr] = buffer;

        return result;
    }
};