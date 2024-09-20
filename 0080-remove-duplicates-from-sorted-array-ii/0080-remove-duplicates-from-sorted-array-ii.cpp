class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if (nums.size() <= 2)
        return nums.size();

        int insertIndex = 2;  
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[insertIndex - 2]) {
                nums[insertIndex] = nums[i]; 
                insertIndex++;
            }
        }
        return insertIndex;
    }
};