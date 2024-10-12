class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> timeline(1000002, 0);
        for (auto& interval : intervals) {
            timeline[interval[0]]++;
            timeline[interval[1] + 1]--;
        }
        int maxGroups = 0, currentGroups = 0;
        for (int count : timeline) {
            currentGroups += count;
            maxGroups = max(maxGroups, currentGroups);
        }
        return maxGroups;
    }
};
