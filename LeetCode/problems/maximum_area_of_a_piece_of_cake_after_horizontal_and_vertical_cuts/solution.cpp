class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int max_horiz = 1;
        int max_vert = 1;
        
        std::sort(horizontalCuts.begin(), horizontalCuts.end());
        std::sort(verticalCuts.begin(), verticalCuts.end());
        
        int prev = 0;

        // Special case for either array being 0 length
        if(horizontalCuts.size() == 0) {
            max_horiz = h;
        }
        else {
            for(int i : horizontalCuts) {
                int diff = i - prev;
                max_horiz = std::max(max_horiz, diff);
                prev = i;
            }
            max_horiz = std::max(max_horiz, h - prev);   
        }
        
        if(verticalCuts.size() == 0) {
            max_vert = w;
        }
        else {
            prev = 0;
            for(int i : verticalCuts) {
                int diff = i - prev;
                max_vert = std::max(max_vert, diff);
                prev = i;
            }
            max_vert = std::max(max_vert, w - prev);   
        }
        
        long long result = (long long)max_horiz * (long long)max_vert;
        return (result % 1000000007);
    }
};