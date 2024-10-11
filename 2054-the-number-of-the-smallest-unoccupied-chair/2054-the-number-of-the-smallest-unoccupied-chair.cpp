class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<int, int>> events;
        for (int i = 0; i < n; ++i) {
            events.push_back({times[i][0], i});
            events.push_back({times[i][1], -i - 1});
        }
        sort(events.begin(), events.end());

        set<int> availableChairs;
        for (int i = 0; i < n; ++i) {
            availableChairs.insert(i);
        }
        
        vector<int> friendChair(n, -1);
        for (auto& event : events) {
            if (event.second >= 0) {
                int chair = *availableChairs.begin();
                availableChairs.erase(availableChairs.begin());
                friendChair[event.second] = chair;
                if (event.second == targetFriend) {
                    return chair;
                }
            } else {
                availableChairs.insert(friendChair[-event.second - 1]);
            }
        }
        return -1;
    }
};
