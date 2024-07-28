class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // Step 1: Map everyone's distinct height to their name
        std::unordered_map<int, std::string> height_to_name;
        for(int i=0;i<heights.size();i++) {
            height_to_name[heights[i]] = names[i];
        }

        // Step 2: Sort the heights in descending order
        std::sort(heights.begin(), heights.end(), std::greater<>());

        // Step 3: Create the result vector from the sorted heights list
        std::vector<string> res(names.size());
        for(int i=0;i<heights.size();i++) {
            res[i] = height_to_name[heights[i]];
        }

        return res;
    }
};
