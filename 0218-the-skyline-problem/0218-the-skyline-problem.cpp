#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events; 
        
        for (auto &b : buildings) {
            events.emplace_back(b[0], -b[2]); 
            events.emplace_back(b[1], b[2]); 
        }

       
        sort(events.begin(), events.end());

        vector<vector<int>> skyline;
        multiset<int> activeHeights = {0};
        int prevMaxHeight = 0;

        for (auto &[x, h] : events) {
            if (h < 0) { 
                activeHeights.insert(-h);
            } else {
                activeHeights.erase(activeHeights.find(h));
            }

            int currentMaxHeight = *activeHeights.rbegin(); 

            if (currentMaxHeight != prevMaxHeight) { 
                skyline.push_back({x, currentMaxHeight});
                prevMaxHeight = currentMaxHeight;
            }
        }
        return skyline;
    }
};
