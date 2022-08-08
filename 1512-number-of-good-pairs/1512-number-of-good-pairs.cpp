class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                ret += nums[i] == nums[j];
            }
        }
        return ret;
    }
};