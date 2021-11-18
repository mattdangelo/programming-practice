class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i=1;i<n+1;i++) {
            string resp = "";
            if(i % 3 == 0) {
                resp = "Fizz";
            }
            
            if(i % 5 == 0) {
                resp += "Buzz";
            }
            
            res.push_back(resp == "" ? to_string(i) : resp);
        }
        return res;
    }
};