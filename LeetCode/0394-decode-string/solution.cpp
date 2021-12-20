class Solution {
public:
    string decodeString(string s) {
        
        int end_par = s.find(']', 0);
        while(end_par != -1) {
            int start_par = end_par - 1;
            while(s[start_par] != '[') {
                start_par--;
            }
            
            string decoded_seg = s.substr(start_par + 1, end_par - start_par - 1);
            string repl_str = "";

            int nums_index = start_par - 1;
            string num_reps_s = "";
            while(isdigit(s[nums_index])) {
                num_reps_s = s[nums_index] + num_reps_s;
                nums_index--;
                if(nums_index == -1) {
                    break;
                }
            }

            int num_reps = stoi(num_reps_s);
                
            for(int j=0;j<num_reps;j++) {
                repl_str += decoded_seg;
            }
            
            s.erase(nums_index + 1, end_par - nums_index);
            s.insert(nums_index + 1, repl_str);
            end_par = s.find(']', 0); 
        }
        
        return s;
    }
};
