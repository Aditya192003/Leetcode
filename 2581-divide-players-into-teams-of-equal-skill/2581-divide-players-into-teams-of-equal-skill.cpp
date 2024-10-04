class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        
        int n = skill.size();
        long long totalChemistry = 0;
        
        int teamSkillSum = skill[0] + skill[n - 1];
        
        for (int i = 0; i < n / 2; ++i) {
            int currentSum = skill[i] + skill[n - 1 - i];
            
            if (currentSum != teamSkillSum) {
                return -1;
            }
            
            totalChemistry += 1LL * skill[i] * skill[n - 1 - i];
        }
        
        return totalChemistry;
    }
};
