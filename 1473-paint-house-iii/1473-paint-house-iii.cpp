class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int dp[200][201][21]; memset(dp, -1, sizeof dp);
        auto go = [&](auto& self, int idx, int neigh, int color) -> int {
            if (idx == m) {
                if (neigh == target) return 0;
                return 0x3f3f3f3f;
            }
            
            int& ret = dp[idx][neigh][color];
            if (~ret) return ret;
            if (houses[idx]) {
                int nxtNeigh = neigh;
                if (idx == 0 || houses[idx - 1] != houses[idx]) ++nxtNeigh;
                return self(self, idx + 1, nxtNeigh, houses[idx]);
            }
            
            ret = 0x3f3f3f3f;
            for (int i = 0; i < n; ++i) {
                int nxtNeigh = neigh, tmp = houses[idx];
                if (idx == 0 || houses[idx - 1] != i + 1) ++nxtNeigh;
                
                houses[idx] = i + 1;
                ret = min(ret, self(self, idx + 1, nxtNeigh, i + 1) + cost[idx][i]);
                houses[idx] = tmp;
            }
            
            return ret;
        };
        
        int ans = go(go, 0, 0, 0);
        
        if (ans == 0x3f3f3f3f) return -1;
        return ans;
    }
};