class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int dp[1001]; memset(dp, -1, sizeof dp);
        auto go = [&](auto& self, int rest) -> int {
            if (rest < 0) return 0;
            if (rest == 0) return 1;
            
            int& ret = dp[rest];
            if (~ret) return ret;
            
            ret = 0;
            for (int num : nums) ret += self(self, rest - num);
            
            return ret;
        };
        
        return go(go, target);
    }
};