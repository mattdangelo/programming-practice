#define MAX_VALUE 1000

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Create a default order mapping for all elements from 0 - MAX_VALUE
        // The order starts from MAX_VALUE + 1 to allow room for arr2's element order
        int order_mapping[MAX_VALUE + 1];
        for(int i=0;i<MAX_VALUE + 1;i++) {
            order_mapping[i] = MAX_VALUE + 1 + i;
        }

        // Map the order of the elements in arr2
        for(int i=0;i<arr2.size();i++) {
            order_mapping[arr2[i]] = i;
        }

        // Sort the elements by their respective order mapping
        std::sort(arr1.begin(), arr1.end(), [&order_mapping](const int& lhs, const int& rhs) {
            return order_mapping[lhs] < order_mapping[rhs];
        });

        return arr1;
    }
};
