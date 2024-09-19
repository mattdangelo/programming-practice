class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // Step 1: Sort the times in ascending order
        std::sort(timePoints.begin(), timePoints.end(), [](const string t1, const string t2) {
            string t1_hour = getHour(t1);
            string t2_hour = getHour(t2);

            if(t1_hour < t2_hour) {
                return true;
            }
            else if(t1_hour > t2_hour) {
                return false;
            }
            else {
                if(getMin(t1) < getMin(t2)) {
                    return true;
                }
                else {
                    return false;
                }
            }
        });

        // Step 2: Walk the list and find the min distance between adjacent elements
        int min = INT_MAX;

        for(int i=0;i<timePoints.size() - 1;i++) {
            int diff = timeDiff(timePoints[i], timePoints[i + 1]);
            min = std::min(min, diff);
        }

        // Step 3: Edge case - compare the first and last elements against eachother,
        // since they wouldn't be compared in the above loop, but are technically adjacent
        int diff = timeDiff(timePoints[0], timePoints[timePoints.size() - 1]);
        min = std::min(min, std::min(diff, 1440 - diff));

        return min;
    }
private:
    int timeDiff(string t1, string t2) {
        // Calculate the hour difference - trivial since we sorted
        int t1_time_normalized = stoi(getHour(t1)) * 60 + stoi(getMin(t1));
        int t2_time_normalized = stoi(getHour(t2)) * 60 + stoi(getMin(t2));

        return t2_time_normalized - t1_time_normalized;
    }

    static string getHour(string s) {
        return s.substr(0, 2);
    }

    static string getMin(string s) {
        return s.substr(3, 2);
    }
};
