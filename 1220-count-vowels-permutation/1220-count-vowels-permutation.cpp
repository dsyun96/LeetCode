class Solution {
public:
    int countVowelPermutation(int n) {
        int dp[20000][5];
        for (int i = 0; i < 5; ++i) dp[0][i] = 1;
        
        const int MOD = 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            dp[i][0] = (0ll + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % MOD;
            dp[i][1] = (0ll + dp[i - 1][0] + dp[i - 1][2]) % MOD;
            dp[i][2] = (0ll + dp[i - 1][1] + dp[i - 1][3]) % MOD;
            dp[i][3] = (0ll + dp[i - 1][2]) % MOD;
            dp[i][4] = (0ll + dp[i - 1][2] + dp[i - 1][3]) % MOD;
        }
        
        return accumulate(dp[n - 1], dp[n - 1] + 5, 0ll) % MOD;
    }
};