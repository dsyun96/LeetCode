class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        
        int dp[101][101]; memset(dp, -1, sizeof dp);
        auto go = [&](auto& self, int a, int b) -> int {
            if (a + b == s3.size()) return 1;
            
            int& ret = dp[a][b];
            if (~ret) return ret;
            
            ret = 0;
            if (a < s1.size() && s3[a + b] == s1[a]) ret |= self(self, a + 1, b);
            if (b < s2.size() && s3[a + b] == s2[b]) ret |= self(self, a, b + 1);
            
            return ret;
        };
        
        return go(go, 0, 0);
    }
};