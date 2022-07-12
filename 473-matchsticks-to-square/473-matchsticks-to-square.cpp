class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4) return false;
        sum /= 4;
        
        char dp[3][1 << 15]; memset(dp, -1, sizeof dp);
        auto go = [&](auto& self, int cnt, int state) -> char {
            if (cnt == 3) return 1;
            
            char& ret = dp[cnt][state];
            if (~ret) return ret;
            
            ret = 0;
            for (int bit = state; bit; bit = bit - 1 & state) {
                int s = 0;
                for (int j = 0; j < n; ++j) if (bit & 1 << j) s += matchsticks[j];
                
                if (s == sum && self(self, cnt + 1, state ^ bit)) return 1;
            }
            
            return ret;
        };
        
        return go(go, 0, (1 << n) - 1);
    }
};