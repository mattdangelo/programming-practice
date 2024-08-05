class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        // Keep track of the unique strings in the array
        std::unordered_map<std::string, bool> string_unique;
        for(std::string s : arr) {
            if(string_unique.count(s)) {
                string_unique[s] = false;
            }
            else {
                string_unique[s] = true;
            }
        }

        // Loop over the array - and incrament a counter for
        // each unique string until we hit k
        int counter = 0;
        for(int i=0;i<arr.size();i++) {
            if(string_unique[arr[i]] == 1) {
                counter++;
                if(counter == k) {
                    return arr[i];
                }
            }
        }

        return "";
    }
};
