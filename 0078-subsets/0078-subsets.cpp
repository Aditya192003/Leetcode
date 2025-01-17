class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& subset, int index) {
        res.push_back(subset);
        
        for (int i = index; i < nums.size(); i++) {
            subset.push_back(nums[i]);          
            backtrack(nums, res, subset, i + 1); 
            subset.pop_back();            
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(nums, res, subset, 0);
        return res;
    }
};
