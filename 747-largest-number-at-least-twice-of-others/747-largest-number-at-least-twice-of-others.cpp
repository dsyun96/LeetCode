class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        auto p = max_element(nums.begin(), nums.end());
        for (auto num : nums) if (num != *p && num * 2 > *p) return -1;
        return p - nums.begin();
    }
};