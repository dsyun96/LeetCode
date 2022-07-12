class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4) return false;
        sum /= 4;
        
        vector<int> valid;
        for (int i = (1 << n) - 1; i; i = i - 1 & (1 << n) - 1) {
            int s = 0;
            for (int j = 0; j < n; ++j) if (i & 1 << j) s += matchsticks[j];
            if (s == sum) valid.push_back(i);
        }
        
        char dp[3][1 << 15]; memset(dp, -1, sizeof dp);
        auto go = [&](auto& self, int cnt, int state) -> char {
            if (cnt == 3) return 1;
            
            char& ret = dp[cnt][state];
            if (~ret) return ret;
            
            ret = 0;
            for (int it : valid) if (!(it & state) && self(self, cnt + 1, state | it)) return 1;
            
            return ret;
        };
        
        return go(go, 0, 0);
    }
};