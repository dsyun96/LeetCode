class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int j = 0, i = 0; i < n; ++i) {
            if (nums[i] < 1 || nums[i] > n) nums[i] = 0;
            else {
                nums[j] = nums[i];
                if (j++ != i) nums[i] = 0;
            }
        }
        
        nums.push_back(0);
        for (int i = 0; i < n; ++i) {
            do {
                int now;
                if (nums[n]) now = nums[n], nums[n] = 0;
                else now = nums[i];
                
                if (now <= 0) break;

                if (now - 1 != i && nums[now - 1] > 0) nums[n] = nums[now - 1];
                nums[i] = 0;
                nums[now - 1] = -1;
            } while (nums[n]);
        }
        
        for (int i = 0; i < n; ++i) if (nums[i] != -1) return i + 1;
        return n + 1;
    }
};