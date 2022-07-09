class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int dp[100000]; dp[0] = nums[0];
        priority_queue<int> PQ, del;
        PQ.emplace(dp[0]);
        
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = PQ.top() + nums[i];
            if (i >= k) del.emplace(dp[i - k]);
            while (!del.empty() && PQ.top() == del.top()) {
                PQ.pop();
                del.pop();
            }
            PQ.emplace(dp[i]);
        }
        
        return dp[nums.size() - 1];
    }
};