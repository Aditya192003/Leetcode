class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        while (!pq.empty()) {
            auto [count1, ch1] = pq.top();
            pq.pop();

            if (res.size() >= 2 && res.back() == ch1 && res[res.size() - 2] == ch1) {
                if (pq.empty()) break;
                auto [count2, ch2] = pq.top();
                pq.pop();
                res += ch2;
                if (--count2 > 0) pq.push({count2, ch2});
                pq.push({count1, ch1});
            } else {
                res += ch1;
                if (--count1 > 0) pq.push({count1, ch1});
            }
        }

        return res;
    }
};
