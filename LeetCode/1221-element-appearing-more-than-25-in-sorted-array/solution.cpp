class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int size = arr.size();
        int last = -1;
        int length = 0;
        for(int i=0;i<arr.size();i++) {
            if(arr[i] == last) {
                length++;
            }
            else {
                length = 1;
                last = arr[i];
            }

            if(length > (size / 4)) {
                return last;
            }
        }

        return -1;
    }
};
