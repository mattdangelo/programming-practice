class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Edge case - if the vector has no elements in it, just return an empty vector
        if(arr.size() == 0) {
            return {};
        }

        // Sort the vector and create a mapping of ranks
        std::vector<int> sorted(arr);
        std::sort(sorted.begin(), sorted.end());
        unordered_map<int, int> rank;

        // Walk the sorted vector
        int current_rank = 1;
        rank[sorted[0]] = 1;
        for(int i=1;i<sorted.size();i++) {
            if(sorted[i] > sorted[i - 1]) {
                current_rank++;
                rank[sorted[i]] = current_rank;
            }
        }

        // Replace the elements in the original array
        for(int i=0;i<arr.size();i++) {
            arr[i] = rank[arr[i]];
        }

        return arr;
    }
};
