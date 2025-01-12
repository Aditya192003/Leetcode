class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, h, mid)) {
                right = mid;  
            } else {
                left = mid + 1;  
            }
        }
        return left;
    }
    
private:
    bool canFinish(vector<int>& piles, int h, int k) {
        int hoursNeeded = 0;
        for (int pile : piles) {
            hoursNeeded += (pile + k - 1) / k;  
        }
        return hoursNeeded <= h;
    }
};
