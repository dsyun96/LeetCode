class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int dp[1000][1000]; memset(dp, 0x3f, sizeof dp);
        auto go = [&](auto& self, int s, int e, int idx = 0) -> int {
            if (s + e == nums.size() || idx == multipliers.size()) return 0;
            
            int& ret = dp[s][e];
            if (ret != 0x3f3f3f3f) return ret;
            
            ret = -0x3f3f3f3f;
            ret = max(ret, nums[s] * multipliers[idx] + self(self, s + 1, e, idx + 1));
            ret = max(ret, nums[nums.size() - 1 - e] * multipliers[idx] + self(self, s, e + 1, idx + 1));
            
            return ret;
        };
        
        return go(go, 0, 0);
    }
};