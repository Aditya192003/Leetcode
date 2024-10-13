class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        int maxElement = INT_MIN;

        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i][0], {i, 0}});
            maxElement = max(maxElement, nums[i][0]);
        }

        int rangeStart = 0, rangeEnd = INT_MAX;
        
        while (true) {
            auto [minElement, indices] = minHeap.top(); minHeap.pop();
            int listIdx = indices.first;
            int elementIdx = indices.second;

            if (maxElement - minElement < rangeEnd - rangeStart) {
                rangeStart = minElement;
                rangeEnd = maxElement;
            }

            if (elementIdx + 1 < nums[listIdx].size()) {
                int nextElement = nums[listIdx][elementIdx + 1];
                minHeap.push({nextElement, {listIdx, elementIdx + 1}});
                maxElement = max(maxElement, nextElement); 
            } else {
                break;
            }
        }

        return {rangeStart, rangeEnd};
    }
};