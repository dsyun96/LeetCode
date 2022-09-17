class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto it : nums) cnt[it]++;
        
        int ans = 0;
        for (auto it : nums) if (cnt.find(it) != cnt.end() && cnt.find(it + 1) != cnt.end()) ans = max(ans, cnt[it] + cnt[it + 1]);
        
        return ans;
    }
};