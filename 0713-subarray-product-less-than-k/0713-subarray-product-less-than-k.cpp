class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
          if (k <= 1) return 0; 
        
        int start = 0, count = 0;
        long long prod = 1; 
        
        for (int end = 0; end < nums.size(); ++end) {
            prod *= nums[end];
            
            while (prod >= k && start <= end) {
                prod /= nums[start++];
            }
            
            count += (end - start + 1);
        }
        
        return count;
    }
};