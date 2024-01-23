#define ASCII_OFFSET 97

class Solution {
    // Array of filtered strings
    std::vector<std::string> filtered_arr;

    // Buffer of 26 bools - used to store whether a character has already been used
    bool used[26];

    // Checks if we can take this element given the ones we're already using
    bool canTake(bool* used, std::string& s) {       
        for(char c : s) {
            if(used[c - ASCII_OFFSET]) {
                return false;
            }
        }

        return true;
    }

    int recMaxLength(int ptr, int count) {
        // Base cases
        if(ptr >= filtered_arr.size() || count == 26) {
            return count;
        }

        // Recurse into the case where we don't take any elements
        int non_taken_branch = recMaxLength(ptr + 1, count);

        if(canTake(used, filtered_arr[ptr])) {
            // Add elements to vector
            for(char c : filtered_arr[ptr]) {
                used[c - ASCII_OFFSET] = true;
                count++;
            }

            // Recurse into the case where we do take the element
            int taken_branch = recMaxLength(ptr + 1, count);
            
            // Clean up elements we added
            for(char c : filtered_arr[ptr]) {
                used[c - ASCII_OFFSET] = false;
                count--;
            }

            return std::max(non_taken_branch, taken_branch);
        }
        else {
            // We can't take the string, so we only need to consider 
            // the path where we don't take the element
            return non_taken_branch;
        }
    }

public:
    int maxLength(vector<string>& arr) {
        filtered_arr.reserve(arr.size());

        for(std::string s : arr) {
            // Wipe the array clean
            for(int i=0;i<26;i++) {
              used[i] = false;
            }

            // Go through the string, if we find duplicate chars, don't 
            // add the string to the filtered list
            for(char c : s) {
                if(used[c - ASCII_OFFSET]) {
                    goto early_exit;
                }
                else {
                    used[c - ASCII_OFFSET] = true;
                }
            }
            filtered_arr.push_back(s);
            early_exit:
        }

        // Wipe used clean - Array repurposed in below method
        for(int i=0;i<26;i++) {
          used[i] = false;
        }

        return recMaxLength(0, 0);
    }
};
