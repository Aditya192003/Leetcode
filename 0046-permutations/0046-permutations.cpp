#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, vector<bool>& visited) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue; 
            
            visited[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, result, current, visited);
            current.pop_back();
            visited[i] = false; 
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> visited(nums.size(), false);
        backtrack(nums, result, current, visited);
        return result;
    }
};
