class Solution {
    long getMaxDiff(int boundry, vector<int>& cuts) {
        int max;

        if(cuts.size() == 0) {
            // Special case for 0 length array
            max = boundry;
        }
        else {
            std::sort(cuts.begin(), cuts.end());
            int prev = 0;
            max = 1;
            int diff;

            for(int i : cuts) {
                diff = i - prev;
                max = std::max(max, diff);
                prev = i;
            }
            max = std::max(max, boundry - prev);   
        }

        return max;
    }
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        return (getMaxDiff(w, verticalCuts) * getMaxDiff(h, horizontalCuts)) % 1000000007;
    }
};
