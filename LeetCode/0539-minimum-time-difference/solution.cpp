class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // Early exist case: If there's more than 1440 entries, there must be at least 1 duplicate,
        // so we can return early
        if(timePoints.size() > 1440) {
            return 0;
        }

        // Step 1: Convert all the times points to minutes since the start of the day
        std::vector<int> minutesSinceDayStart(timePoints.size());
        for(int i=0;i<timePoints.size();i++) {
            minutesSinceDayStart[i] = minutesSinceMidnight(timePoints[i]);
        }

        // Step 2: Sort the times in ascending order
        std::sort(minutesSinceDayStart.begin(), minutesSinceDayStart.end());

        // Step 3: Walk the list and find the min distance between adjacent elements
        int min = INT_MAX;

        for(int i=0;i<minutesSinceDayStart.size() - 1;i++) {
            min = std::min(min, minutesSinceDayStart[i+1] - minutesSinceDayStart[i]);
        }

        // Step 4: Edge case - compare the first and last elements against eachother,
        // since they wouldn't be compared in the above loop, but are technically adjacent
        int diff = minutesSinceDayStart[minutesSinceDayStart.size() - 1] - minutesSinceDayStart[0];
        min = std::min(min, std::min(diff, 1440 - diff));

        return min;
    }
private:
    inline int minutesSinceMidnight(string s) {
        return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
    }
};
