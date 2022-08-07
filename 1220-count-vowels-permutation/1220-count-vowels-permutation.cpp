class Solution {
public:
    int countVowelPermutation(int n) {
        int dp[2][5];
        for (int i = 0; i < 5; ++i) dp[0][i] = 1;
        
        const int MOD = 1e9 + 7;
        int idx = 0;
        for (int i = 1; i < n; ++i) {
            idx ^= 1;
            dp[idx][0] = (0ll + dp[idx ^ 1][1] + dp[idx ^ 1][2] + dp[idx ^ 1][4]) % MOD;
            dp[idx][1] = (0ll + dp[idx ^ 1][0] + dp[idx ^ 1][2]) % MOD;
            dp[idx][2] = (0ll + dp[idx ^ 1][1] + dp[idx ^ 1][3]) % MOD;
            dp[idx][3] = (0ll + dp[idx ^ 1][2]) % MOD;
            dp[idx][4] = (0ll + dp[idx ^ 1][2] + dp[idx ^ 1][3]) % MOD;
        }
        
        return accumulate(dp[idx], dp[idx] + 5, 0ll) % MOD;
    }
};