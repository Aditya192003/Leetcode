class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
          priority_queue<int> pq(nums.begin(), nums.end());
        long long score = 0;

        while (k--) {
            int top = pq.top();
            pq.pop();
            score += top;
            pq.push(ceil(top / 3.0));
        }

        return score;
    }
};