class Solution {
public:
    int minSwaps(string s) {
        int imbalance = 0; 
        int max_imbalance = 0; 
        
        for (char c : s) {
            if (c == '[') {
                imbalance--; 
            } else {
                imbalance++; 
            }
            
            max_imbalance = max(max_imbalance, imbalance);
        }
        
        return (max_imbalance + 1) / 2;
    }
};
