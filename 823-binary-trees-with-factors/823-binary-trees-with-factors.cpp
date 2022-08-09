class Solution {
public:
    const int MOD = 1000000007;
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, int> D;
        for (int i = 0; i < arr.size(); ++i) D[arr[i]] = i;
        
        int dp[1000]; memset(dp, -1, sizeof dp);
        auto go = [&](auto& self, int idx) -> int {
            int& ret = dp[idx];
            if (~ret) return ret;
            
            ret = 1;
            for (int i = 0; i < arr.size(); ++i) if (arr[idx] % arr[i] == 0 && D.find(arr[idx] / arr[i]) != D.end()) {
                ret = (ret + 1ll * self(self, i) * self(self, D[arr[idx] / arr[i]])) % MOD;
            }
            
            return ret;
        };
        
        int ret = 0;
        for (int i = 0; i < arr.size(); ++i) ret = (ret + go(go, i)) % MOD;
        
        return ret;
    }
};