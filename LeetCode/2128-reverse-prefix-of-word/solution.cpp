class Solution {
public:
    string reversePrefix(string word, char ch) {
        // Step 1: Find the ocurrence of ch if it exists, this will be our right boundry
        int right = -1;
        for(int i=0;i<word.length();i++) {
            if(word[i] == ch) {
                right = i;
                break;
            }
        }

        // If we didn't find ch in the string, do nothing
        if(right == -1) {
            return word;
        }

        // Step 2: Reverse the string from index 0 to the right boundry
        int left = 0;
        while(left < right) {
            char temp = word[left];
            word[left] = word[right];
            word[right] = temp;
            left++;
            right--;
        }

        return word;
    }
};
