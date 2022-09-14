class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<int> pos[50000];
        for (int i = 0; i < nums.size(); ++i) pos[nums[i]].push_back(i);
        
        int mx = -1, ans = 0;
        for (int i = 0; i < 50000; ++i) {
            if (pos[i].empty() || mx > (int)pos[i].size()) continue;
            if (mx < (int)pos[i].size()) ans = pos[i].back() - pos[i].front() + 1;
            else ans = min(ans, pos[i].back() - pos[i].front() + 1);
            mx = pos[i].size();
        }
        
        return ans;
    }
};