class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        std::deque<int> q;
        int flips = 0;

        for(int i=0;i<nums.size();i++) {
            // Remove the elements from the queue that aren't relevant anymore
            while(!q.empty() && i > (q.front() + k - 1)) {
                q.pop_front();
            }

            if((nums[i] + q.size()) % 2 == 0) {
                // There aren't enough elements left, so it's not possible
                if(i + k > nums.size()) {
                    return -1;
                }

                // Flip it
                flips++;
                q.push_back(i);
            }
        }

        return flips;
    }
};
