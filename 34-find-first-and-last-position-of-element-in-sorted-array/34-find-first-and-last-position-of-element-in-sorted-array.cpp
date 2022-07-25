class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto res = equal_range(nums.begin(), nums.end(), target);
        if (res.first == res.second) return { -1, -1 };
        return { int(res.first - nums.begin()), int(res.second - nums.begin()) - 1 };
    }
};