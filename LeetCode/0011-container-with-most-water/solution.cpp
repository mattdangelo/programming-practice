class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int best = 0;
        while(l < r) {
            int l_best = min(height[l], height[r]) * (r - l);
            if(l_best > best) {
                best = l_best;
            }
            if(height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        
        return best;
    }
};
