class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int ans = 0, dif = 0x3f3f3f3f;
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int now = nums[i] + nums[j] + nums[k];
                if (dif > abs(now - target)) {
                    dif = abs(now - target);
                    ans = now;
                }
                
                if (now > target) --k;
                else ++j;
            }
        }
        
        return ans;
    }
};