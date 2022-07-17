class Solution {
public:
    const int MOD = 1000000007;
    
    int kInversePairs(int n, int k) {
        int dp[1001][1001]{}; dp[1][0] = 1;
        for (int i = 2; i <= n; ++i) {
            int sum_[1002]{}, *sum = sum_ + 1;
            for (int j = 0; j <= k; ++j) sum[j] = (sum[j - 1] + dp[i - 1][j]) % MOD;
            
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = (sum[j] - sum[max(-1, j - i)]) % MOD;
                if (dp[i][j] < 0) dp[i][j] += MOD;
            }
        }
        
        return dp[n][k];
    }
};