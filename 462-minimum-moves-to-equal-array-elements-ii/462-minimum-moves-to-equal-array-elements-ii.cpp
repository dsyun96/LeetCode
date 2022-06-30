class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        for (int it : nums) ans += abs(nums[nums.size() / 2] - it);
        
        return ans;
    }
};