class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
         int n = arr.size();
        vector<int> prefix(n); 
        vector<int> result;

        prefix[0] = arr[0];
        for(int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] ^ arr[i];
        }

        for(auto& q : queries) {
            int left = q[0], right = q[1];
            if (left == 0) 
                result.push_back(prefix[right]);
            else 
                result.push_back(prefix[right] ^ prefix[left - 1]);
        }
        return result;
    }
};