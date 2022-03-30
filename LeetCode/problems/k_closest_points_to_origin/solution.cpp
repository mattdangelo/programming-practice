class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::sort(points.begin(), points.end(), [](const std::vector<int> & a, const std::vector<int> & b) -> bool
        { 
            return (a.at(0) * a.at(0) + a.at(1) * a.at(1)) < (b.at(0) * b.at(0) + b.at(1) * b.at(1)); 
        });

        
        return vector<vector<int>> (points.begin(), points.begin() + k);
    }
};