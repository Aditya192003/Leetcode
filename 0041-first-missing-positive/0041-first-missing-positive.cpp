class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
         int n = nums.size();
        
        // Step 1: Place each number in its correct position if possible
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Step 2: Find the first position where the index does not match the value
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // If all positions are correct, the missing number is n + 1
        return n + 1;
    }
};