class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[200]; dp[0] = 1;
        for (int i = 1; i <= n + m - 2; ++i) {
            for (int j = i; j >= 0; --j) {
                if (j == i || j == 0) dp[j] = 1;
                else dp[j] = (0ll + dp[j] + dp[j - 1]) % 2000000000;
            }
        }
        
        return dp[m - 1];
    }
};