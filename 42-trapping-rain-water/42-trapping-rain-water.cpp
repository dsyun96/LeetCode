class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int suf[20001]; suf[n] = 0;
        for (int i = height.size(); --i; ) suf[i] = max(suf[i + 1], height[i]);
        
        int ans = 0;
        for (int p = 0, i = 0; i < n; ++i) {
            ans += max(0, min(p, suf[i + 1]) - height[i]);
            p = max(p, height[i]);
        }
        
        return ans;
    }
};