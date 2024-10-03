
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL) % p;
        
        if (totalSum == 0) return 0;
        
        unordered_map<int, int> prefixMap;
        prefixMap[0] = -1; 
        long long prefixSum = 0;
        int minLength = nums.size();
        
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum = (prefixSum + nums[i]) % p;
            
            int target = (prefixSum - totalSum + p) % p;
            
            if (prefixMap.find(target) != prefixMap.end()) {
                minLength = min(minLength, i - prefixMap[target]);
            }
            
            prefixMap[prefixSum] = i;
        }
        
        return minLength == nums.size() ? -1 : minLength;
    }
};