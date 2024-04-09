class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) {
            return false;
        }
        
        int left = 0;
        int right = arr.size() - 1;
        
        while(left < arr.size()) {
            if(arr[left + 1] > arr[left]) {
                left++;
            }
            else {
                break;
            }
        }
        
        if(left == 0) {
            return false;
        }
        
        while(right > 0) {
            if(arr[right] < arr[right - 1]) {
                right--;
            }
            else {
                break;
            }
        }

        if(right == arr.size() - 1) {
            return false;
        }
        
        return left == right;
    }
};