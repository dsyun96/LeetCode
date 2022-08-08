class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int lis[2500], len = 0;
        for (int num : nums) {
            int* p = lower_bound(lis, lis + len, num);
            *p = num;
            len += p == lis + len;
        }
        return len;
    }
};