class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        
        vector<int> vec{ nums[0] };
        int i;
        for (i = 1; i < nums.size(); ++i) if (nums[i] != nums[0]) {
            vec.push_back(nums[i]);
            break;
        }
        if (i == nums.size()) return 1;
        
        for (int sz = 2; ++i < nums.size(); ) {
            if (vec[sz - 2] < vec[sz - 1]) {
                if (vec[sz - 1] <= nums[i]) vec[sz - 1] = nums[i];
                else vec.push_back(nums[i]), ++sz;
            }
            else {
                if (vec[sz - 1] >= nums[i]) vec[sz - 1] = nums[i];
                else vec.push_back(nums[i]), ++sz;
            }
        }
        
        return vec.size();
    }
};