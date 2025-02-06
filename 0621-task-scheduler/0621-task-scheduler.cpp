class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         unordered_map<char, int> freq;
        int maxFreq = 0, maxCount = 0;
        
        for (char task : tasks) {
            freq[task]++;
            if (freq[task] > maxFreq) {
                maxFreq = freq[task];
                maxCount = 1;
            } else if (freq[task] == maxFreq) {
                maxCount++;
            }
        }
        
        int partCount = maxFreq - 1; 
        int partSize = n + 1;           
        int minTime = partCount * partSize + maxCount;
        
        return max(minTime, (int)tasks.size());
    }
};