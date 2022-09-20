class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        int dp[1000][1000]; memset(dp, -1, sizeof dp);
        auto go = [&](auto& self, int a, int b) -> int {
            if (a >= n || b >= m) return 0;
            if (nums1[a] != nums2[b]) return 0;
            
            int& ret = dp[a][b];
            if (~ret) return ret;
            
            return ret = self(self, a + 1, b + 1) + 1;
        };
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = max(ans, go(go, i, j));
            }
        }
        
        return ans;
    }
};