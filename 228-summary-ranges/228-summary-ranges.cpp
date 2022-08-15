class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        for (int p = 0, i = 0; i < nums.size(); ++i) {
            if (i && nums[i - 1] + 1 != nums[i]) {
                if (p != i - 1) ret.push_back(to_string(nums[p]) + "->" + to_string(nums[i - 1]));
                else ret.push_back(to_string(nums[i - 1]));
                p = i;
            }
            if (i == nums.size() - 1) {
                if (p != i) ret.push_back(to_string(nums[p]) + "->" + to_string(nums[i]));
                else ret.push_back(to_string(nums[i]));
            }
        }
        return ret;
    }
};