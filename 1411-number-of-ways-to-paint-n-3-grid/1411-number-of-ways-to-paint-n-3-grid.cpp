class Solution {
public:
    int numOfWays(int n) {
        int dp[5001][4][4][4]; memset(dp, -1, sizeof dp);
        auto go = [&](auto& self, int now, int a, int b, int c) -> int {
            if (now == 0) return 1;
            
            int& ret = dp[now][a][b][c];
            if (~ret) return ret;
            
            ret = 0;
            for (int i = 0; i < 3; ++i) if (a != i) {
                for (int j = 0; j < 3; ++j) if (i != j && b != j) {
                    for (int k = 0; k < 3; ++k) if (j != k && c != k) {
                        ret = (ret + self(self, now - 1, i, j, k)) % 1000000007;
                    }
                }
            }
            
            return ret;
        };
        
        return go(go, n, 3, 3, 3);
    }
};