class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        for (int& num : nums) {
            num = lower_bound(sortedNums.begin(), sortedNums.end(), num) - sortedNums.begin() + 1;
        }
        
        int n = nums.size();
        vector<int> BIT(n + 1, 0); 
        vector<int> result(n, 0);
        
        auto update = [&](int index, int value) {
            while (index <= n) {
                BIT[index] += value;
                index += index & (-index); 
            }
        };
        
        auto query = [&](int index) {
            int sum = 0;
            while (index > 0) {
                sum += BIT[index];
                index -= index & (-index); 
            }
            return sum;
        };
        
        for (int i = n - 1; i >= 0; --i) {
            result[i] = query(nums[i] - 1);
            update(nums[i], 1); 
        }
        
        return result;
    }
};