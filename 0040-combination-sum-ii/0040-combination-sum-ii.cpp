#include <vector>
#include <algorithm>

class Solution {
public:
    void backtrack(std::vector<int>& candidates, int target, int start, 
                   std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue; 
            if (candidates[i] > target) break; 
            
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, current, result);
            current.pop_back();
        }
    }
    
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end()); 
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};
