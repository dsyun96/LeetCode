class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int cnt_[20001]{}, *cnt = cnt_ + 10000;
        for (auto num : nums) cnt[num]++;
        
        int hold = 0;
        for (int i = 10000; i >= -10000; --i) {
            hold += cnt[i];
            if (hold >= k) return i;
        }
        
        return 0;
    }
};