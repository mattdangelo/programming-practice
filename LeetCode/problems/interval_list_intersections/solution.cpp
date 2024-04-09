class Solution {
public:
    vector<int> overlap(int l1, int r1, int l2, int r2) {
        vector<int> ret = {-1, -1};

        if(l1 <= r2 && r1 >= l2) {
            ret[0] = max(l1, l2);
            ret[1] = min(r1, r2);
        }

        return ret;
    }

    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> results;
        if(firstList.size() == 0 || secondList.size() == 0) {
            return results;
        }
        
        int sp = 0;
        int fp = 0;
        
        while(fp != firstList.size() && sp != secondList.size()) {
            vector<int> olp = overlap(firstList[fp][0], firstList[fp][1], secondList[sp][0], secondList[sp][1]);
            if(olp[0] != -1) {
                // Overlap happened, add to range
                results.push_back(olp);
            }
            
            if(firstList[fp][1] < secondList[sp][1]) {
                fp++;
            }
            else {
                sp++;
            }
        }
        
        return results;
    }
};